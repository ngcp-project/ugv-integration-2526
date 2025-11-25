import socket
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from ugv_msgs.msg import ManCtrl, AutoCtrl  # ensure these match your .msg files


class UgvArmControlSubNode(Node):
    def __init__(self):
        super().__init__('ugv_armcontrol_sub')

        # ---- Parameters (override at runtime with --ros-args -p key:=value) ----
        # Local bind address (same as your RTI script)
        self.declare_parameter('server_ip', '0.0.0.0')
        self.declare_parameter('server_port', 12345)
        # Destination (client) address
        self.declare_parameter('client_ip', '192.168.20.21')  # change this
        self.declare_parameter('client_port', 8)

        # Get parameter values
        self.server_ip = (
            self.get_parameter('server_ip')
            .get_parameter_value()
            .string_value
            or '0.0.0.0'
        )
        self.server_port = (
            self.get_parameter('server_port')
            .get_parameter_value()
            .integer_value
            or 12345
        )
        self.client_ip = (
            self.get_parameter('client_ip')
            .get_parameter_value()
            .string_value
            or '192.168.20.21'
        )
        self.client_port = (
            self.get_parameter('client_port')
            .get_parameter_value()
            .integer_value
            or 8
        )

        # ---- UDP socket setup (bind + sendto) ----
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            self.sock.bind((self.server_ip, int(self.server_port)))
            self.get_logger().info(
                f'UDP bound to {self.server_ip}:{self.server_port}, '
                f'sending to {self.client_ip}:{self.client_port}'
            )
        except Exception as ex:
            self.get_logger().error(f'UDP bind failed: {ex}')
            raise

        # ---- Subscriptions ----
        qos = QoSProfile(depth=10)
        self.man_sub = self.create_subscription(
            ManCtrl, 'man_ctrl', self.on_man_ctrl, qos
        )
        self.auto_sub = self.create_subscription(
            AutoCtrl, 'auto_ctrl', self.on_auto_ctrl, qos
        )

        # Constants used in auto callback (tweak as needed)
        self.ARM_CMD = 0.0

    # --- man_ctrl callback ---
    def on_man_ctrl(self, msg: ManCtrl):
        # If autonomous is enabled in the ManCtrl, skip manual drive payloads
        if getattr(msg, 'auto_en', False):
            self.get_logger().debug('Manual suppressed (auto_en=True).')
            return

        arm_cmd = round(float(getattr(msg, 'arm_cmd', 0.0)), 3)

        payload = f'{arm_cmd}'.encode()
        try:
            self.sock.sendto(payload, (self.client_ip, int(self.client_port)))
            self.get_logger().debug(f'Sent MAN arm_cmd={arm_cmd}')
        except Exception as ex:
            self.get_logger().warning(f'UDP send (MAN) failed: {ex}')

    # --- auto_ctrl callback ---
    def on_auto_ctrl(self, msg: AutoCtrl):
        # If your AutoCtrl.msg includes "float32 heading_error", send only when nonzero.
        heading_error = float(getattr(msg, 'heading_error', 0.0))
        if heading_error == 0.0:
            return

        auto_flag = 1.0
        payload = f'{self.ARM_CMD},{auto_flag},{heading_error:.3f}'.encode()
        try:
            self.sock.sendto(payload, (self.client_ip, int(self.client_port)))
            self.get_logger().debug(
                f'Sent ARM_CMD={self.ARM_CMD}, flag={auto_flag}, '
                f'err={heading_error:.3f}'
            )
        except Exception as ex:
            self.get_logger().warning(f'UDP send (AUTO) failed: {ex}')

    def destroy_node(self):
        try:
            if hasattr(self, 'sock'):
                self.sock.close()
        finally:
            super().destroy_node()


def main():
    rclpy.init()
    node = UgvArmControlSubNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
