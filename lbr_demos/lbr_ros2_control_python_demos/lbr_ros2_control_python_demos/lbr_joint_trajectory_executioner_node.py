import rclpy
from control_msgs.action import FollowJointTrajectory
from rclpy.action import ActionClient
from rclpy.node import Node
from trajectory_msgs.msg import JointTrajectoryPoint


class LBRJointTrajectoryExecutionerNode(Node):
    def __init__(
        self,
        node_name: str,
        robot_name: str = "lbr",
    ) -> None:
        super().__init__(node_name=node_name)
        self.robot_name_ = robot_name
        self.joint_trajectory_action_client_ = ActionClient(
            node=self,
            action_type=FollowJointTrajectory,
            action_name="/position_trajectory_controller/follow_joint_trajectory",
        )
        while not self.joint_trajectory_action_client_.wait_for_server(1):
            self.get_logger().info("Waiting for action server to become available...")
        self.get_logger().info("Action server available.")

    def execute(self, positions: list, sec_from_start: int = 10):
        if len(positions) != 7:
            self.get_logger().error("Invalid number of joint positions.")
            return

        joint_trajectory_goal = FollowJointTrajectory.Goal()
        goal_sec_tolerance = 1
        joint_trajectory_goal.goal_time_tolerance.sec = goal_sec_tolerance

        point = JointTrajectoryPoint()
        point.positions = positions
        point.time_from_start.sec = sec_from_start

        for i in range(7):
            joint_trajectory_goal.trajectory.joint_names.append(
                f"{self.robot_name_}_joint_{i}"
            )

        joint_trajectory_goal.trajectory.points.append(point)

        # send goal
        goal_future = self.joint_trajectory_action_client_.send_goal_async(
            joint_trajectory_goal
        )
        rclpy.spin_until_future_complete(self, goal_future)
        goal_handle = goal_future.result()
        if not goal_handle.accepted:
            self.get_logger().error("Goal was rejected by server.")
            return
        self.get_logger().info("Goal was accepted by server.")

        # wait for result
        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(
            self, result_future, timeout_sec=sec_from_start + goal_sec_tolerance
        )

        if (
            result_future.result().result.error_code
            != FollowJointTrajectory.Result.SUCCESSFUL
        ):
            self.get_logger().error("Failed to execute joint trajectory.")
            return


def main(args: list = None) -> None:
    rclpy.init(args=args)
    lbr_joint_trajectory_executioner_node = LBRJointTrajectoryExecutionerNode(
        "lbr_joint_trajectory_executioner_node"
    )

    # rotate odd joints
    lbr_joint_trajectory_executioner_node.get_logger().info("Rotating odd joints.")
    lbr_joint_trajectory_executioner_node.execute(
        [
            1.0,
            0.0,
            1.0,
            0.0,
            1.0,
            0.0,
            1.0,
        ]
    )

    # move to zero position
    lbr_joint_trajectory_executioner_node.get_logger().info("Moving to zero position.")
    lbr_joint_trajectory_executioner_node.execute(
        [
            0.0,
            0.0,
            0.0,
            0.0,
            0.0,
            0.0,
            0.0,
        ]
    )

    rclpy.shutdown()
