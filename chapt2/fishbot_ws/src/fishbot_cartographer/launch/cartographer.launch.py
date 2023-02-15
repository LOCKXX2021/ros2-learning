import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    package_name = 'fishbot_cartographer'
    pkg_share = get_package_share_directory(package_name)

    #使用仿真时间(使用gazebo故使用)
    use_sim_time = LaunchConfiguration('use_sim_time',default='true')
    #地图分辨率
    resolution = LaunchConfiguration('resolution',default='0.05')
    # 发布周期
    publish_period_sec = LaunchConfiguration('publish_period_sec',default='1.0')
    #配置文件路径
    configuration_directory = LaunchConfiguration('configuration_directory',default=os.path.join(pkg_share,'config') )
    #配置文件
    configuration_basename = LaunchConfiguration('configuration_basename',default='fishbot_2d.lua')
    rviz_config_dir = os.path.join(pkg_share,'config')+"/cartographer.rviz"
    print(f"rviz config in {rviz_config_dir}")

    cartographer_node = Node(
        package='cartographer_ros',
        executable='cartographer_node',
        name='cartographer_node',
        parameters= [{'use_sim_time':use_sim_time}],
        arguments= ['-configuration_directory',configuration_directory,
                    '-configuration_basename',configuration_basename],
        output = "screen"
    )
    cartographer_grid_node = Node(
        package='cartographer_ros',
        executable='cartographer_occupancy_grid_node',
        name='cartographer_occupancy_grid_node',
        parameters= [{'use_sim_time':use_sim_time}],
        arguments= ['-resolution', resolution, '-publish_period_sec', publish_period_sec],
        output = "screen"
    )
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        parameters= [{'use_sim_time':use_sim_time}],
        arguments= ['-d',rviz_config_dir],
        output = "screen"

    )
    return LaunchDescription([
        cartographer_node,
        cartographer_grid_node,
        rviz_node
    ])
