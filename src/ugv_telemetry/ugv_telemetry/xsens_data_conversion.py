import math
# import socket
import struct
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Vector3Stamped
from ugv_msgs.msg import UGVTelemetry

M_PER_S_TO_FT_PER_S = 3.28084
METERS_TO_FEET = 3.28084

# Binary packet layout (50 bytes, little-endian):
# Bytes  0-1  : reserved          (2 bytes)
# Bytes  2-5  : speed_fps         (float32)
# Bytes  6-9  : pitch_deg         (float32)
# Bytes 10-13 : yaw_deg           (float32)
# Bytes 14-17 : roll_deg          (float32)
# Bytes 18-21 : altitude_ft       (float32)
# Bytes 22-33 : reserved          (12 bytes)
# Bytes 34-41 : latitude          (float64)
# Bytes 42-49 : longitude         (float64)
PACKET_FORMAT = '<xx fffff 12x dd'


class XsensDataConversion(Node):
    def __init__(self):
        super().__init__('xsens_data_conversion')

        # TODO: configure GCS IP and port before enabling UDP
        # self.declare_parameter('gcs_ip', '192.168.1.100')
        # self.declare_parameter('gcs_port', 5005)
        # gcs_ip = self.get_parameter('gcs_ip').get_parameter_value().string_value
        # gcs_port = self.get_parameter('gcs_port').get_parameter_value().integer_value
        # self._sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        # self._gcs_addr = (gcs_ip, gcs_port)

        self._velocity = None
        self._euler = None
        self._position = None

        self.create_subscription(Vector3Stamped, '/filter/velocity', self._velocity_cb, 10)
        self.create_subscription(Vector3Stamped, '/filter/euler', self._euler_cb, 10)
        self.create_subscription(Vector3Stamped, '/filter/positionlla', self._position_cb, 10)

        self._pub = self.create_publisher(UGVTelemetry, '/ngcp/telemetry', 10)
        self.create_timer(0.1, self._publish)  # 10 Hz

        # self.get_logger().info(f'Sending UDP telemetry packets to {gcs_ip}:{gcs_port}')

    def _velocity_cb(self, msg: Vector3Stamped):
        self._velocity = msg.vector

    def _euler_cb(self, msg: Vector3Stamped):
        # xsens euler: x=roll, y=pitch, z=yaw (degrees)
        self._euler = msg.vector

    def _position_cb(self, msg: Vector3Stamped):
        # xsens positionlla: x=lat, y=lon, z=altitude (meters)
        self._position = msg.vector

    def _publish(self):
        if self._velocity is None and self._euler is None and self._position is None:
            return

        vel = self._velocity
        eul = self._euler
        pos = self._position

        speed_fps   = math.sqrt(vel.x ** 2 + vel.y ** 2) * M_PER_S_TO_FT_PER_S if vel else 0.0
        pitch_deg   = float(eul.y) if eul else 0.0
        yaw_deg     = float(eul.z) if eul else 0.0
        roll_deg    = float(eul.x) if eul else 0.0
        altitude_ft = float(pos.z * METERS_TO_FEET) if pos else 0.0
        latitude    = float(pos.x) if pos else 0.0
        longitude   = float(pos.y) if pos else 0.0

        out = UGVTelemetry()
        out.speed_fps   = float(speed_fps)
        out.pitch_deg   = pitch_deg
        out.yaw_deg     = yaw_deg
        out.roll_deg    = roll_deg
        out.altitude_ft = altitude_ft
        out.latitude    = latitude
        out.longitude   = longitude
        self._pub.publish(out)


def main(args=None):
    rclpy.init(args=args)
    node = XsensDataConversion()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
