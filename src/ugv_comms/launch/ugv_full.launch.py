from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from pathlib import Path


def generate_launch_description():
    repo_root = str(Path(__file__).resolve().parent.parent.parent.parent)
    xsens_params = Path(get_package_share_directory('xsens_mti_ros2_driver'), 'param', 'xsens_mti_node.yaml')
    ntrip_params = Path(get_package_share_directory('ntrip'), 'config', 'ntrip-param.yaml')
    teleop_launch = Path(get_package_share_directory('ugv_teleop'), 'launch', 'ugv_control.launch.py')

    xsens_port_arg = DeclareLaunchArgument(
        'xsens_port', default_value='/dev/ttyUSB1',
        description='Serial port for the Xsens MTi IMU',
    )
    xbee_port_arg = DeclareLaunchArgument(
        'xbee_port', default_value='/dev/ttyUSB3',
        description='Serial port for the XBee module',
    )
    gcs_mac_arg = DeclareLaunchArgument(
        'gcs_mac_address', default_value='0013A200427EA7FC',
        description='64-bit MAC address of the GCS XBee',
    )
    vehicle_mac_arg = DeclareLaunchArgument(
        'vehicle_mac_address', default_value='0013A20042839F3E',
        description='64-bit MAC address of this vehicle XBee',
    )

    return LaunchDescription([
        SetEnvironmentVariable('RCUTILS_CONSOLE_OUTPUT_FORMAT', '[{severity}] [{name}]: {message}'),
        xsens_port_arg,
        xbee_port_arg,
        gcs_mac_arg,
        vehicle_mac_arg,

        # Xsens IMU driver
        Node(
            package='xsens_mti_ros2_driver',
            executable='xsens_mti_node',
            name='xsens_mti_node',
            output='screen',
            parameters=[str(xsens_params), {
                'port': LaunchConfiguration('xsens_port'),
            }],
        ),

        # NTRIP client (RTK corrections)
        Node(
            package='ntrip',
            executable='ntrip',
            name='ntrip_client',
            output='screen',
            parameters=[str(ntrip_params)],
        ),

        # Xsens -> /ngcp/telemetry bridge
        Node(
            package='ugv_telemetry',
            executable='xsens_data_conversion',
            name='xsens_data_conversion',
            output='screen',
        ),

        # Teleop control (crsf_joy_node, ugv_control_pub, ugv_control_sub)
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(teleop_launch)),
        ),

        # XBee command receiver
        Node(
            package='ugv_comms',
            executable='xb_r',
            name='xb_r',
            output='screen',
            parameters=[{
                'xbee_port':           LaunchConfiguration('xbee_port'),
                'gcs_mac_address':     LaunchConfiguration('gcs_mac_address'),
                'vehicle_mac_address': LaunchConfiguration('vehicle_mac_address'),
                'workspace_root':      repo_root,
            }],
        ),

        # XBee telemetry sender
        Node(
            package='ugv_comms',
            executable='xb_s',
            name='xb_s',
            output='screen',
        ),
    ])
