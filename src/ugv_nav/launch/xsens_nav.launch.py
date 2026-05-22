from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ugv_nav',
            executable='xsens_subscriber',
            name='xsens_local_xy_subscriber',
            output='screen',
            parameters=[{
                'gps_topic': '/filter/positionlla',
                'euler_topic': '/filter/euler',
                'xy_topic': '/gnss_local',
                'heading_topic': '/xsens/heading_deg',
                'cmd_topic': 'man_ctrl',
                'heading_offset_deg': 30.0,
                'min_turn_radius': 2.0,
                'lookahead_distance': 1.5,
                'linear_speed': 0.5,
                'goal_tolerance_m': 1.5,
                'max_runtime_sec': 30.0,
                'max_steering_deg': 30.0,
                'max_velocity_mps': 1.0,
                'min_rtk_for_origin': 1,
                'log_every_fix': True,
            }]
        ),
    ])
