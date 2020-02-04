# Fast Robot Interface ROS2

This folder will contain a lightweight ROS wrapper for KUKA's Fast Robot Interface, for which we modified the build system to a target based CMake approach, to be cross platform compatible, as well as modular.

# Build

```shell
source /opt/ros/melodic/setup.bash
mkdir -p fri_ws/src
cd fri_ws/src
git clone --recursive https://github.com/KCL-BMEIS/fri_ros2.git
catkin_make
```

# Launch
## Gazebo


## Real Robot


## Rviz2


# Notes
urdfexport https://github.com/syuntoku14/fusion2urdf
