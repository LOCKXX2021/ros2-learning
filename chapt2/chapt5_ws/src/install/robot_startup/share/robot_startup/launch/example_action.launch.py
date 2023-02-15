from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    """launch内容描述函数,由ros2 launch扫描调用"""
    action_robot_02 = Node(
        package="example_action_rclpy",
        executable="action_robot_02"

    )
    action_control_02 = Node(
        package="example_action_rclpy",
        executable="action_control_02"

    )
    launch_description = LaunchDescription(
        [action_robot_02,action_control_02]
    )
    return launch_description