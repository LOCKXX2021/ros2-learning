import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_path
def generate_launch_description():
    package_name = "fishbot_description"
    urdf_name = "fishbot_base.urdf"
    pkg_share = get_package_share_path(package_name)

    # pkg_share = FindPackageShare(package=package_name).find(package_name)
    urdf_model_path = os.path.join(pkg_share,f"urdf/{urdf_name}")

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        arguments=[urdf_model_path]
        )

    # joint_state_publisher_node = Node(
    #     package='joint_state_publisher_gui',
    #     executable='joint_state_publisher_gui',
    #     name='joint_state_publisher_gui',
    #     arguments=[urdf_model_path]
    #     )

    rviz2_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        )

    return LaunchDescription([
        robot_state_publisher_node,
        # joint_state_publisher_node,
        rviz2_node

        
        
        ])