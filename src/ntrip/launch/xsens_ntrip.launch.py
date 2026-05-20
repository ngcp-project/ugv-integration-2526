from launch import LaunchDescription
from launch.actions import SetEnvironmentVariable
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from pathlib import Path


def generate_launch_description():
    ld = LaunchDescription()

    ld.add_action(SetEnvironmentVariable('RCUTILS_LOGGING_USE_STDOUT', '1'))
    ld.add_action(SetEnvironmentVariable('RCUTILS_LOGGING_BUFFERED_STREAM', '1'))

    xsens_params = Path(
        get_package_share_directory('xsens_mti_ros2_driver'),
        'param', 'xsens_mti_node.yaml',
    )
    ld.add_action(Node(
        package='xsens_mti_ros2_driver',
        executable='xsens_mti_node',
        name='xsens_mti_node',
        output='screen',
        parameters=[xsens_params],
    ))

    ld.add_action(Node(
        package='ntrip',
        executable='ntrip',
        name='ntrip_client',
        output='screen',
        parameters=[{
            'host': 'ntrip.earthscope.org',
            'port': 2101,
            'mountpoint': 'CLAR_RTCM3P3',
            'username': 'confident_kowalevski',
            'password': '0bt0VSR2vxHrZn2g',
        }],
        remappings=[
            ('nmea', 'nmea'),
            ('rtcm', 'rtcm'),
        ],
    ))

    return ld
