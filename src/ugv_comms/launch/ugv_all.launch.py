from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from pathlib import Path


def generate_launch_description():
    repo_root = str(Path(__file__).resolve().parent.parent.parent.parent)
    xsens_params = Path(get_package_share_directory('xsens_mti_ros2_driver'), 'param', 'xsens_mti_node.yaml')

    xbee_port_arg = DeclareLaunchArgument(
        'xbee_port',
        default_value='/dev/ttyUSB3',
        description='Serial port for the XBee module',
    )
    gcs_mac_arg = DeclareLaunchArgument(
        'gcs_mac_address',
        default_value='0013A200427EA7FC',
        description='64-bit MAC address of the GCS XBee',
    )
    vehicle_mac_arg = DeclareLaunchArgument(
        'vehicle_mac_address',
        default_value='0013A20042839F3E',
        description='64-bit MAC address of this vehicle XBee',
    )

    return LaunchDescription([
        xbee_port_arg,
        gcs_mac_arg,
        vehicle_mac_arg,

        # Xsens IMU driver
        Node(
            package='xsens_mti_ros2_driver',
            executable='xsens_mti_node',
            name='xsens_mti_node',
            output='screen',
            parameters=[str(xsens_params)],
        ),

        # Xsens → /ngcp/telemetry bridge
        Node(
            package='ugv_telemetry',
            executable='xsens_data_conversion',
            name='xsens_data_conversion',
            output='screen',
        ),

        # XBee comms
        Node(
            package='ugv_comms',
            executable='xbee_command_receiver',
            name='xb-r',
            output='screen',
            parameters=[{
                'xbee_port':           LaunchConfiguration('xbee_port'),
                'gcs_mac_address':     LaunchConfiguration('gcs_mac_address'),
                'vehicle_mac_address': LaunchConfiguration('vehicle_mac_address'),
                'workspace_root':      repo_root,
            }],
        ),
    ])
