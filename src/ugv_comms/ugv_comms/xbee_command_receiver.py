
import json
import threading
import time

import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool, String
from geometry_msgs.msg import Point
from ugv_msgs.msg import UGVTelemetry, ManCtrl

# Normal imports. run pip install -e . in every submodule
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


# ros2 launch ugv_comms ugv_comms.launch.py xbee_port:=/dev/ttyUSB0 \
#     gcs_mac_address:=0013A200427EA7FC \
#     vehicle_mac_address:=0013A20042839F3E

XBEE_PORT = 'COM3'  
GCS_MAC_ADDRESS = '0013A200427EA7FC' # GCS xbee
VEHICLE_MAC_ADDRESS = '0013A20042839F3E'  # Jetson xbee

class XBeeCommandReceiver(Node):
    def __init__(self):
        super().__init__('xbee_command_receiver')

        self.declare_parameter('xbee_port', XBEE_PORT)
        self.declare_parameter('gcs_mac_address', GCS_MAC_ADDRESS)
        self.declare_parameter('vehicle_mac_address', VEHICLE_MAC_ADDRESS)

        xbee_port      = self.get_parameter('xbee_port').value
        gcs_mac        = self.get_parameter('gcs_mac_address').value
        vehicle_mac    = self.get_parameter('vehicle_mac_address').value

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

        # Latest joystick control state (updated by man_ctrl subscriber)
        self._latest_vel = 0.0
        self._latest_steer = 0.0
        self._latest_arm = [0.0, 0.0]
        self._ctrl_lock = threading.Lock()

        # Publishers
        self._estop_pub   = self.create_publisher(Bool,   '/ngcp/estop',            10)
        self._patient_pub = self.create_publisher(Point,  '/ngcp/patient_location',  10)
        self._zone_pub    = self.create_publisher(String, '/ngcp/add_zone',          10)

        # Subscriber: real telemetry from Xsens / sensor fusion
        self.create_subscription(UGVTelemetry, '/ngcp/telemetry', self._on_telemetry, 10)

        # Subscriber: joystick control data
        self.create_subscription(ManCtrl, 'man_ctrl', self._on_man_ctrl, 10)

        # Stop event before any possible early return
        self._stop_event = threading.Event()

        # Start XBee threads
        # Call launchVehicleXbee from infrascruture's launch vehicleXbee that calls StartVehicleXBee which then calls vehicleXbee 
        try:
            LaunchVehicleXBee(xbee_port)
            self.get_logger().info(f'XBee started on {xbee_port} with vehicle MAC address {vehicle_mac}')
        except Exception as e:
            self.get_logger().error(f'Failed to open XBee on {xbee_port} and mac address {vehicle_mac}: {e}')
            return

        # Send joystick control data via XBee at 2 Hz
        self.create_timer(0.5, self._periodic_telemetry)

        # ReceiveCommand blocks on Queue.get(), so it runs in its own thread
        self._cmd_thread = threading.Thread(
            target=self._command_loop, daemon=True, name='xbee_cmd_recv'
        )
        self._cmd_thread.start()

    # Callbacks
    
    def _on_telemetry(self, msg: UGVTelemetry):
        with self._telem_lock:
            self._latest_telemetry = msg

    def _on_man_ctrl(self, msg: ManCtrl):
        with self._ctrl_lock:
            self._latest_vel = float(msg.linear_vel)
            self._latest_steer = float(msg.steer_cmd)
            self._latest_arm = [float(msg.arm_cmd[0]), float(msg.arm_cmd[1])]

    def _periodic_telemetry(self):
        with self._ctrl_lock:
            vel = self._latest_vel
            steer = self._latest_steer
            arm = list(self._latest_arm)

        with self._telem_lock:
            src = self._latest_telemetry

        if src is not None:
            telem = self._Telemetry(
                CommandID=0,
                PacketID=0,
                Speed=vel,
                Pitch=float(src.pitch_deg),
                Yaw=steer,
                Roll=float(src.roll_deg),
                Altitude=float(src.altitude_ft),
                CurrentPosition=(float(src.latitude), float(src.longitude)),
                BatteryLife=arm[0],
                LastUpdated=int(arm[1]),
                VehicleStatus=1,
            )
        else:
            telem = self._Telemetry(
                CommandID=0,
                PacketID=0,
                Speed=vel,
                Yaw=steer,
                BatteryLife=arm[0],
                LastUpdated=int(arm[1]),
                VehicleStatus=1,
            )

        try:
            self._SendTelemetry(telem)
            self.get_logger().info(
                f'[CTRL TX] vel={vel:.3f} steer={steer:.3f} '
                f'arm=[{arm[0]:.1f}, {arm[1]:.1f}]'
            )
        except Exception as e:
            self.get_logger().error(f'Periodic telemetry send failed: {e}')

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
            self._reply_telemetry(command)

        elif isinstance(command, self._EmergencyStop):
            activate = (command.StopStatus == 0)
            self.get_logger().warn(
                f'[CMD 2] EmergencyStop — {"ACTIVATE" if activate else "RELEASE"}'
            )
            msg = Bool()
            msg.data = activate
            self._estop_pub.publish(msg)
            self._reply_telemetry(command)

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
            self._reply_telemetry(command)

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
            self._reply_telemetry(
                command,
                message_flag=2,
                message_lat=command.Coordinates[0],
                message_lon=command.Coordinates[1],
            )

        else:
            self.get_logger().warn(f'Unhandled command type: {type(command).__name__}')

    def _reply_telemetry(self, command, message_flag=0,
                         message_lat=0.0, message_lon=0.0, patient_status=0):
        """Build a Telemetry packet from the latest Xsens sensor data and queue it for XBee TX.

        Echoes back the command's COMMAND_ID and PacketID so the GCS can
        correlate which command this telemetry is responding to.
        """
        cmd_id = getattr(command, 'COMMAND_ID', 0)
        pkt_id = getattr(command, 'PacketID', 0)

        with self._telem_lock:
            src = self._latest_telemetry

        if src is not None:
            telem = self._Telemetry(
                CommandID=cmd_id,
                PacketID=pkt_id,
                Speed=float(src.speed_fps),
                Pitch=float(src.pitch_deg),
                Yaw=float(src.yaw_deg),
                Roll=float(src.roll_deg),
                Altitude=float(src.altitude_ft),
                CurrentPosition=(float(src.latitude), float(src.longitude)),
                BatteryLife=0.0,
                VehicleStatus=1,
                MessageFlag=message_flag,
                MessageLat=message_lat,
                MessageLon=message_lon,
                PatientStatus=patient_status,
            )
        else:
            telem = self._Telemetry(
                CommandID=cmd_id,
                PacketID=pkt_id,
                VehicleStatus=1,
                MessageFlag=message_flag,
                MessageLat=message_lat,
                MessageLon=message_lon,
                PatientStatus=patient_status,
            )

        try:
            self._SendTelemetry(telem)
            self.get_logger().info(
                f'Telemetry reply sent for CMD {cmd_id} (pkt {pkt_id}) — '
                f'lat: {telem.CurrentPositionX:.6f}, lon: {telem.CurrentPositionY:.6f}'
            )
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
