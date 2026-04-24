import os
import sys
import json
import threading
import time
from pathlib import Path

import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool, String
from geometry_msgs.msg import Point
from ugv_msgs.msg import UGVTelemetry

# adding lib paths(submodules from gcs) so we can import.
def _add_lib_paths(workspace_root: str):
    root = Path(workspace_root)
    paths = [
        root / 'lib' / 'gcs-infrastructure' / 'Application',
        root / 'lib' / 'gcs-packet' / 'Packet',
        root / 'lib' / 'xbee-python' / 'src',
    ]
    for p in paths:
        p_str = str(p)
        if p_str not in sys.path:
            sys.path.insert(0, p_str)

XBEE_PORT = 'COM3'  
GCS_MAC_ADDRESS = '0013A200427EA7FC'  
VEHICLE_MAC_ADDRESS = '0013A20042839F3E'  

class XBeeCommandReceiver(Node):
    def __init__(self):
        super().__init__('xbee_command_receiver')

        self.declare_parameter('xbee_port', XBEE_PORT)
        self.declare_parameter('gcs_mac_address', GCS_MAC_ADDRESS)
        self.declare_parameter('vehicle_mac_address', VEHICLE_MAC_ADDRESS)

        # Path to repo root; falls back to $UGV_WS_ROOT or ~/ugv-integration-2526
        self.declare_parameter('workspace_root',os.environ.get('UGV_WS_ROOT', str(Path.home() / 'ugv-integration-2526')))

        xbee_port      = self.get_parameter('xbee_port').value
        gcs_mac        = self.get_parameter('gcs_mac_address').value
        vehicle_mac    = self.get_parameter('vehicle_mac_address').value
        workspace_root = self.get_parameter('workspace_root').value

        # Inject lib paths before any gcs-* imports
        _add_lib_paths(workspace_root)

        # Late imports — depend on sys.path being set above
        from Infrastructure.InfrastructureInterface import (
            LaunchVehicleXBee, ReceiveCommand, SendTelemetry,
        )
        from Command.Heartbeat import Heartbeat
        from Command.EmergencyStop import EmergencyStop
        from Command.AddZone import AddZone
        from Command.PatientLocation import PatientLocation
        from Enum.DecodeFormat import DecodeFormat
        from Enum.Vehicle import Vehicle
        from PacketLibrary.PacketLibrary import PacketLibrary
        from Telemetry.Telemetry import Telemetry

        # Store refs so threads can reach them
        self._ReceiveCommand  = ReceiveCommand
        self._SendTelemetry   = SendTelemetry
        self._Heartbeat       = Heartbeat
        self._EmergencyStop   = EmergencyStop
        self._AddZone         = AddZone
        self._PatientLocation = PatientLocation
        self._DecodeFormat    = DecodeFormat
        self._Telemetry       = Telemetry

        #  MAC address configuration 
        if gcs_mac:
            PacketLibrary.SetGCSMACAddress(gcs_mac)
        else:
            self.get_logger().warn(
                'gcs_mac_address is not set — telemetry replies will not transmit. '
                'Pass it via launch arg: gcs_mac_address:=0013A200XXXXXXXX'
            )

        if vehicle_mac:
            PacketLibrary.SetVehicleMACAddress(Vehicle.MRA, vehicle_mac)

        #  Latest telemetry snapshot (updated by /ngcp/telemetry subscriber) 
        self._latest_telemetry: UGVTelemetry | None = None
        self._telem_lock = threading.Lock()

        # Publishers 
        self._estop_pub   = self.create_publisher(Bool,   '/ngcp/estop',            10)
        self._patient_pub = self.create_publisher(Point,  '/ngcp/patient_location',  10)
        self._zone_pub    = self.create_publisher(String, '/ngcp/add_zone',          10)

        # Subscriber: real telemetry from Xsens / sensor fusion
        self.create_subscription(UGVTelemetry, '/ngcp/telemetry', self._on_telemetry, 10)

        # Start XBee threads
        # Call launchVehicleXbee from infrascruture's launch vehicleXbee whic calls StartVehicleXBee which calls vehicleXbee 
        try:
            LaunchVehicleXBee(xbee_port)
            self.get_logger().info(f'XBee started on {xbee_port} with vehicle MAC address {vehicle_mac}')
        except Exception as e:
            self.get_logger().error(f'Failed to open XBee on {xbee_port} and mac address {vehicle_mac}: {e}')
            return

        # ReceiveCommand blocks on Queue.get(), so it runs in its own thread
        self._stop_event = threading.Event()
        self._cmd_thread = threading.Thread(
            target=self._command_loop, daemon=True, name='xbee_cmd_recv'
        )
        self._cmd_thread.start()

    # Callbacks 
    def _on_telemetry(self, msg: UGVTelemetry):
    # every time ROS receives a new telemetry, we update out latest telem snapshot
        with self._telem_lock:
            self._latest_telemetry = msg

    def _command_loop(self):
        # wait for XBee commands then sends them to _dispatch
        while not self._stop_event.is_set():
            try:
                command = self._ReceiveCommand(self._DecodeFormat.Class)
                self._dispatch(command)
            except Exception as e:
                self.get_logger().error(f'Command receive error: {e}')
                time.sleep(0.1)

    def _dispatch(self, command):
        # receives XBee commands and publishes to ROS
        
        if command is None:
            self.get_logger().warn('Received unrecognised command ID, ignoring')
            return

        if isinstance(command, self._Heartbeat):
            self.get_logger().info(
                f'[CMD 1] Heartbeat — status: {command.CurrentConnectionStatus}'
            )
            self._reply_telemetry()

        elif isinstance(command, self._EmergencyStop):
            # StopStatus 0 = ACTIVATE stop, 1 = RELEASE stop
            activate = (command.StopStatus == 0)
            self.get_logger().warn(
                f'[CMD 2] EmergencyStop — {"ACTIVATE" if activate else "RELEASE"}'
            )
            msg = Bool()
            msg.data = activate
            self._estop_pub.publish(msg)
            self._reply_telemetry()

        elif isinstance(command, self._AddZone):
            self.get_logger().info(
                f'[CMD 3] AddZone — type: {command.Zone}, '
                f'zone_id: {command.ZoneID}, coords: {command.Coordinates}'
            )
            payload = {
                'zone_type':   command.Zone.value,
                'zone_id':     command.ZoneID,
                'coordinates': list(command.Coordinates),
            }
            msg = String()
            msg.data = json.dumps(payload)
            self._zone_pub.publish(msg)

        elif isinstance(command, self._PatientLocation):
            self.get_logger().info(
                f'[CMD 5] PatientLocation — lat: {command.Coordinates[0]}, '
                f'lon: {command.Coordinates[1]}'
            )
            msg = Point()
            msg.x = command.Coordinates[0]
            msg.y = command.Coordinates[1]
            msg.z = 0.0
            self._patient_pub.publish(msg)

        else:
            self.get_logger().warn(f'Unhandled command type: {type(command).__name__}')

    def _reply_telemetry(self):
        """Build a Telemetry packet from the latest sensor data and queue it for XBee TX."""
        with self._telem_lock:
            src = self._latest_telemetry

        if src is not None:
            telem = self._Telemetry(
                Speed=float(src.speed_fps),
                Pitch=float(src.pitch_deg),
                Yaw=float(src.yaw_deg),
                Roll=float(src.roll_deg),
                Altitude=float(src.altitude_ft),
                CurrentPosition=(float(src.latitude), float(src.longitude)),
                BatteryLife=0.0,
                VehicleStatus=1,
            )
        else:
            # No telemetry data yet — send zeros so the GCS still gets a reply
            telem = self._Telemetry(VehicleStatus=1)

        try:
            self._SendTelemetry(telem)
        except Exception as e:
            self.get_logger().error(f'Failed to queue telemetry reply: {e}')

    def destroy_node(self):
        self._stop_event.set()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = XBeeCommandReceiver()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
