from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable, IncludeLaunchDescription, OpaqueFunction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from pathlib import Path
import serial.tools.list_ports
import sys

FTDI_VID = 0x0403
XSENS_VID = 0x2639


def _resolve_ports(xbee_requested, xsens_requested):
    """Resolve 'auto' port values to real device paths."""
    if xbee_requested != 'auto' and xsens_requested != 'auto':
        return xbee_requested, xsens_requested

    all_ports = sorted(serial.tools.list_ports.comports(), key=lambda p: p.device)
    print(f'[port_detect] Found {len(all_ports)} serial port(s):', file=sys.stderr)
    for p in all_ports:
        desc = p.description or ''
        mfr = p.manufacturer or ''
        vid = f' VID:PID={p.vid:04X}:{p.pid:04X}' if p.vid else ''
        print(f'  {p.device}  {desc}  mfr={mfr}{vid}', file=sys.stderr)

    xsens_port = xsens_requested
    xbee_port = xbee_requested

    if xsens_requested == 'auto':
        for p in all_ports:
            text = ' '.join([p.description or '', p.manufacturer or '', p.product or '']).lower()
            if 'xsens' in text or 'mti' in text or p.vid == XSENS_VID:
                xsens_port = p.device
                break

    if xbee_requested == 'auto':
        used = {xsens_port} if xsens_port != 'auto' else set()
        remaining = [p for p in all_ports if p.device not in used]
        for p in remaining:
            text = ' '.join([p.description or '', p.manufacturer or '', p.product or '']).lower()
            if 'xbee' in text or 'digi' in text:
                xbee_port = p.device
                break
        if xbee_port == 'auto':
            for p in remaining:
                if p.vid == FTDI_VID:
                    xbee_port = p.device
                    break
        if xbee_port == 'auto' and len(remaining) == 1:
            xbee_port = remaining[0].device

    print(f'[port_detect] Resolved: XBee={xbee_port}  Xsens={xsens_port}', file=sys.stderr)
    return xbee_port, xsens_port


def _launch_setup(context):
    repo_root = str(Path(__file__).resolve().parent.parent.parent.parent)
    xsens_params = Path(get_package_share_directory('xsens_mti_ros2_driver'), 'param', 'xsens_mti_node.yaml')
    ntrip_params = Path(get_package_share_directory('ntrip'), 'config', 'ntrip-param.yaml')
    teleop_launch = Path(get_package_share_directory('ugv_teleop'), 'launch', 'ugv_control.launch.py')

    xbee_requested = LaunchConfiguration('xbee_port').perform(context)
    xsens_requested = LaunchConfiguration('xsens_port').perform(context)
    gcs_mac = LaunchConfiguration('gcs_mac_address').perform(context)
    vehicle_mac = LaunchConfiguration('vehicle_mac_address').perform(context)

    xbee_port, xsens_port = _resolve_ports(xbee_requested, xsens_requested)

    return [
        Node(
            package='xsens_mti_ros2_driver',
            executable='xsens_mti_node',
            name='xsens_mti_node',
            output='screen',
            parameters=[str(xsens_params), {'port': xsens_port}],
        ),
        Node(
            package='ntrip',
            executable='ntrip',
            name='ntrip_client',
            output='screen',
            parameters=[str(ntrip_params)],
        ),
        Node(
            package='ugv_telemetry',
            executable='xsens_data_conversion',
            name='xsens_data_conversion',
            output='screen',
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(teleop_launch)),
        ),
        Node(
            package='ugv_comms',
            executable='xb_r',
            name='xb_r',
            output='screen',
            parameters=[{
                'xbee_port':           xbee_port,
                'gcs_mac_address':     gcs_mac,
                'vehicle_mac_address': vehicle_mac,
                'workspace_root':      repo_root,
            }],
        ),
        Node(
            package='ugv_comms',
            executable='xb_s',
            name='xb_s',
            output='screen',
        ),
    ]


def generate_launch_description():
    return LaunchDescription([
        SetEnvironmentVariable('RCUTILS_CONSOLE_OUTPUT_FORMAT', '[{severity}] [{name}]: {message}'),
        DeclareLaunchArgument('xsens_port', default_value='/dev/xsens',
                              description='Serial port for the Xsens MTi IMU (udev symlink; pass "auto" for auto-detect)'),
        DeclareLaunchArgument('xbee_port', default_value='/dev/xbee',
                              description='Serial port for the XBee module (udev symlink; pass "auto" for auto-detect)'),
        DeclareLaunchArgument('gcs_mac_address', default_value='0013A200427EA7FC',
                              description='64-bit MAC address of the GCS XBee'),
        DeclareLaunchArgument('vehicle_mac_address', default_value='0013A20042839F3E',
                              description='64-bit MAC address of this vehicle XBee'),
        OpaqueFunction(function=_launch_setup),
    ])
