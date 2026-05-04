from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ugv_teleop',
            executable='crsf_joy_node',
            name='crsf_joy_node',
            output='screen',
            parameters=[{
                'port': '/dev/ttyTHS1',
                'baud': 420000,
                'deadzone': 0.05,
            }]
        ),
        Node(
            package='ugv_teleop',
            executable='ugv_control_pub',
            name='ugv_control_pub',
            output='screen',
            parameters=[{
                'arm0_lower_limit': 0.0,
                'arm0_upper_limit': 170.0,
                'arm1_lower_limit': 75.0,
                'arm1_upper_limit': 225.0,
                'inc_dec_val': 8.0,
                'publish_rate': 50.0,
                'log_interval': 0.5,
            }]
        ),
        Node(
            package='ugv_teleop',
            executable='ugv_control_sub',
            name='ugv_control_sub',
            output='screen',
            parameters=[{
                'arm_ip': '169.254.155.100',
                'arm_port': 8,
                'drive_ip': '169.254.155.101',
                'drive_port': 9,
                'heartbeat_timeout': 3.0,
                'arm_refresh_interval': 0.5,
            }]
        ),
    ])
