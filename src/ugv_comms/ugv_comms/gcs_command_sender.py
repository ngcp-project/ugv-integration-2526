import rclpy
from rclpy.node import Node
from ugv_msgs.msg import UGVTelemetry

from Infrastructure.InfrastructureInterface import SendTelemetry
from Telemetry.Telemetry import Telemetry


class XBeeTelemetrySender(Node):
    def __init__(self):
        super().__init__("xb_s")

        self.create_subscription(UGVTelemetry, "/ngcp/telemetry", self._on_telemetry, 10)
        self.get_logger().info("XBee telemetry sender ready — forwarding /ngcp/telemetry via XBee")

    def _on_telemetry(self, msg: UGVTelemetry):
        telem = Telemetry(
            CommandID=0,
            PacketID=0,
            Speed=float(msg.speed_fps),
            Pitch=float(msg.pitch_deg),
            Yaw=float(msg.yaw_deg),
            Roll=float(msg.roll_deg),
            Altitude=float(msg.altitude_ft),
            CurrentPosition=(float(msg.latitude), float(msg.longitude)),
            BatteryLife=0.0,
            VehicleStatus=1,
        )

        try:
            SendTelemetry(telem)
            self.get_logger().info(
                f"[TELEM TX] Speed={msg.speed_fps:.2f} Pitch={msg.pitch_deg:.2f} "
                f"Yaw={msg.yaw_deg:.2f} Roll={msg.roll_deg:.2f} Alt={msg.altitude_ft:.2f} "
                f"Pos=({msg.latitude:.6f}, {msg.longitude:.6f})"
            )
        except Exception as e:
            self.get_logger().error(f"XBee telemetry send failed: {e}")


def main(args=None):
    rclpy.init(args=args)
    node = XBeeTelemetrySender()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
