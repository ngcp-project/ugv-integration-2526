from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from pathlib import Path


def generate_launch_description():
    # Resolve the repo root as the parent of this launch file's package directory.
    # Layout: <repo_root>/src/ugv_comms/launch/ugv_comms.launch.py
    repo_root = str(Path(__file__).resolve().parent.parent.parent.parent)

    xbee_port_arg = DeclareLaunchArgument(
        'xbee_port',
        default_value='/dev/ttyUSB0',
        description='Serial port for the XBee module (e.g. /dev/ttyUSB0 or /dev/ttyTHS1)',
    )
    gcs_mac_arg = DeclareLaunchArgument(
        'gcs_mac_address',
        default_value='',
        description='64-bit MAC address of the GCS XBee (hex, no separators). '
                    'Example: 0013A20042435EA9',
    )
    vehicle_mac_arg = DeclareLaunchArgument(
        'vehicle_mac_address',
        default_value='',
        description='64-bit MAC address of this vehicle XBee (hex, no separators).',
    )

    xbee_node = Node(
        package='ugv_comms',
        executable='xbee_command_receiver',
        name='xbee_command_receiver',
        output='screen',
        parameters=[{
            'xbee_port':         LaunchConfiguration('xbee_port'),
            'gcs_mac_address':   LaunchConfiguration('gcs_mac_address'),
            'vehicle_mac_address': LaunchConfiguration('vehicle_mac_address'),
            'workspace_root':    repo_root,
        }],
    )

    return LaunchDescription([
        xbee_port_arg,
        gcs_mac_arg,
        vehicle_mac_arg,
        xbee_node,
    ])
