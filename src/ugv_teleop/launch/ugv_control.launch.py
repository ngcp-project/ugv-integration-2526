from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            output='screen',
            parameters=[{'dev': '/dev/input/js0'}]
        ),
        Node(
            package='ugv_teleop',
            executable='ugv_control_pub',
            name='ugv_control_pub',
            output='screen'
        ),
        Node(
            package='ugv_teleop',
            executable='ugv_control_sub',
            name='ugv_control_sub',
            output='screen'
        ),
    ])
