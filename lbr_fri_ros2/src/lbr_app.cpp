#include "lbr_fri_ros2/lbr_app.hpp"

namespace lbr_fri_ros2
{
    LBRApp::LBRApp(const std::string &node_name, const int &port_id, const char *const remote_host)
        : rclcpp::Node(node_name)
    {
        if (!valid_port_(port_id))
        {
            throw std::range_error("Invalid port_id provided.");
        }
        port_id_ = port_id;
        remote_host_ = remote_host;

        connected_ = false;

        app_connect_srv_ = this->create_service<lbr_fri_msgs::srv::AppConnect>(
            "/lbr_app/connect",
            std::bind(&LBRApp::app_connect_cb_, this, std::placeholders::_1, std::placeholders::_2), rmw_qos_profile_system_default);

        app_disconnect_srv_ = this->create_service<lbr_fri_msgs::srv::AppDisconnect>(
            "/lbr_app/disconnect",
            std::bind(&LBRApp::app_disconnect_cb_, this, std::placeholders::_1, std::placeholders::_2), rmw_qos_profile_system_default);

        lbr_state_client_ = std::make_unique<lbr_fri_ros2::LBRStateClient>("lbr_state_client_node");
        connection_ = std::make_unique<KUKA::FRI::UdpConnection>();
        app_ = std::make_unique<KUKA::FRI::ClientApplication>(*connection_.get(), *lbr_state_client_.get());
    }

    LBRApp::~LBRApp()
    {
        disconnect_();
    }

    void LBRApp::app_connect_cb_(
        const lbr_fri_msgs::srv::AppConnect::Request::SharedPtr request,
        lbr_fri_msgs::srv::AppConnect::Response::SharedPtr response)
    {
        const char *remote_host = request->remote_host.empty() ? NULL : request->remote_host.c_str();
        try
        {
            response->connected = connect_(request->port_id, remote_host);
        }
        catch (const std::exception &e)
        {
            response->message = e.what();
            RCLCPP_ERROR(get_logger(), "Failed. %s", e.what());
        }
    }

    void LBRApp::app_disconnect_cb_(
        const lbr_fri_msgs::srv::AppDisconnect::Request::SharedPtr /*request*/,
        lbr_fri_msgs::srv::AppDisconnect::Response::SharedPtr response)
    {
        try
        {
            response->disconnected = disconnect_();
        }
        catch (const std::exception &e)
        {
            response->message = e.what();
            RCLCPP_ERROR(get_logger(), "Failed. %s", e.what());
        }
    }

    bool LBRApp::valid_port_(const int &port_id)
    {
        if (port_id < 30200 ||
            port_id > 30209)
        {
            RCLCPP_ERROR(get_logger(), "Expected port_id id in [30200, 30209], got %d.", port_id);
            return false;
        }
        return true;
    }

    bool LBRApp::connect_(const int &port_id, const char *const remote_host)
    {
        RCLCPP_INFO(get_logger(), "Attempting to open UDP socket for LBR server...");
        if (!connected_)
        {
            if (!valid_port_(port_id))
            {
                throw std::range_error("Invalid port_id provided.");
            }
            connected_ = app_->connect(port_id, remote_host);
            if (connected_)
            {
                port_id_ = port_id;
                remote_host_ = remote_host;

                auto app_step = [this]()
                {
                    bool success = true;
                    while (success && connected_ && rclcpp::ok())
                    {
                        try
                        {
                            success = app_->step();
                        }
                        catch (const std::exception &e)
                        {
                            RCLCPP_ERROR(get_logger(), e.what());
                            break;
                        }
                    }
                    if (connected_)
                    {
                        disconnect_();
                    }
                };

                app_step_thread_ = std::make_unique<std::thread>(app_step);
                app_step_thread_->detach();
            }
        }
        else
        {
            RCLCPP_INFO(get_logger(), "Port already open.");
        }
        if (connected_)
        {
            RCLCPP_INFO(get_logger(), "Connected successfully.");
        }
        else
        {
            RCLCPP_WARN(get_logger(), "Failed to connect.");
        }
        return connected_;
    }

    bool LBRApp::disconnect_()
    {
        RCLCPP_INFO(get_logger(), "Attempting to close UDP socket for LBR server...");
        if (connected_)
        {
            app_->disconnect();
            connected_ = false;
        }
        else
        {
            RCLCPP_INFO(get_logger(), "Port already closed.");
        }
        if (!connected_)
        {
            RCLCPP_INFO(get_logger(), "Disonnected successfully.");
        }
        else
        {
            RCLCPP_WARN(get_logger(), "Failed to disconnect.");
        }
        return !connected_;
    }
} // end of namespace lbr_fri_ros2
