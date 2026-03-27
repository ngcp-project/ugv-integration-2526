import socket
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from ugv_msgs.msg import ManCtrl, AutoCtrl  # ensure these match your .msg files

'''
Unnecessary function below, this was needed for older rclpy versions, but now we can use get_parameter to simplify all this.
'''

# def get_typed_param(node: Node, name: str, default):
#     """Typed parameter helper so you can pass ints/strings cleanly."""
#     p = node.get_parameter(name).get_parameter_value()
#     # rclpy stores different types in different fields
#     if hasattr(p, "string_value") and p.string_value != "":
#         return p.string_value
#     if hasattr(p, "integer_value") and p.integer_value != 0:
#         return int(p.integer_value)
#     if hasattr(p, "double_value") and p.double_value != 0.0:
#         return float(p.double_value)
#     if hasattr(p, "bool_value"):
#         return bool(p.bool_value)
#     # Fallback to default when parameter was declared but left at type 0
#     return default

class UgvControlSubNode(Node):
    def __init__(self):
        super().__init__('ugv_control_sub')

        self.declare_parameter('server_ip', '0.0.0.0')
        self.declare_parameter('server_port', 12345)
        # Destination (client) address
        # dont change the ip
        # should be
        # self.declare_parameter('client_ip', '192.168.20.21')
        # self.declare_parameter('client_port', 8)

        self.declare_parameter('client_ip', '192.168.20.21')
        self.declare_parameter('client_port', 8)
        # autovel and autosteer params
        self.declare_parameter('auto_vel', -1.0)
        self.declare_parameter('auto_steer', 0.0)

        server_ip        = self.get_parameter('server_ip').value
        server_port      = int(self.get_parameter('server_port').value)
        self.client_ip   = self.get_parameter('client_ip').value
        self.client_port = int(self.get_parameter('client_port').value)
        self.auto_vel    = float(self.get_parameter('auto_vel').value)
        self.auto_steer  = float(self.get_parameter('auto_steer').value)

        # ---- UDP socket setup (bind + sendto) ----
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            self.sock.bind((server_ip, server_port))
            self.get_logger().info(
                f'UDP bound to {server_ip}:{server_port}, sending to {self.client_ip}:{self.client_port}'
            )
        except Exception as ex:
            self.get_logger().error(f'UDP bind failed: {ex}')
            raise

        # ---- Subscriptions ----
        qos = QoSProfile(depth=10)
        self.man_sub = self.create_subscription(ManCtrl, 'man_ctrl', self.on_man_ctrl, qos)
        self.auto_sub = self.create_subscription(AutoCtrl, 'auto_ctrl', self.on_auto_ctrl, qos)

        # Constants used in auto callback (tweak as needed)
        self.AUTO_VEL = -1.0 # make these parameters later
        self.STEER_CMD = 0.0


    # --- man_ctrl callback ---
    def on_man_ctrl(self, msg: ManCtrl):
        # If autonomous is enabled in the ManCtrl, skip manual drive payloads
        if getattr(msg, 'auto_en', False):
            self.get_logger().debug('Manual suppressed (auto_en=True).')
            return

        linear_vel = msg.linear_vel
        steer_cmd = msg.steer_cmd
        arm_cmd = msg.arm_cmd # joints

        # linear_vel = round(float(getattr(msg, 'linear_vel', 0.0)), 3)
        # steer_cmd  = round(float(getattr(msg, 'steer_cmd', 0.0)), 3)

        payload = f'{linear_vel},{steer_cmd}, {",".join(str(x) for x in arm_cmd)}'.encode()
        try:
            self.sock.sendto(payload, (self.client_ip, int(self.client_port)))
            self.get_logger().info(f'Sent MAN {linear_vel=}, {steer_cmd=}, Payload = {payload}')
        except Exception as ex:
            self.get_logger().warning(f'UDP send (MAN) failed: {ex}')

    # --- auto_ctrl callback ---
    def on_auto_ctrl(self, msg: AutoCtrl):
        # If your AutoCtrl.msg includes "float32 heading_error", send only when nonzero.
        heading_error = float(getattr(msg, 'heading_error', 0.0))
        if heading_error == 0.0:
            return

        auto_flag = 1.0
        payload = f'{self.AUTO_VEL},{self.STEER_CMD},{auto_flag},{heading_error:.3f}'.encode()
        try:
            self.sock.sendto(payload, (self.client_ip, int(self.client_port)))
            self.get_logger().debug(
                f'Sent AUTO vel={self.AUTO_VEL}, steer={self.STEER_CMD}, flag={auto_flag}, err={heading_error:.3f}'
            )
        except Exception as ex:
            self.get_logger().warning(f'UDP send (AUTO) failed: {ex}')

    def destroy_node(self): # added shutdown msg
        self.get_logger().info('Shutting down UDP subscriber node...')
        try:
            if hasattr(self, 'sock'):
                self.sock.close()
        finally:
            super().destroy_node()

def main():
    rclpy.init()
    node = UgvControlSubNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
