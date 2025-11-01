#!/usr/bin/env python3
import socket
from typing import Tuple

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

from ugv_msgs.msg import ManCtrl

class UgvContolSub(Node):
    def __init__(self):
        super().__init__('ugv_control_sub')

        self.declare_parameter('bind_ip', '192.168.20.5')
        self.declare_parameter('bind_port', 54321)
        self.declare_parameter('client_ip', '192.168.20.42')
        self.declare_parameter('client_port', 8)
        self.declare_parameter('topic', 'man_ctrl')

        bind_ip = self.get_parameter('bind_ip').get_parameter_value().string_value
        bind_port = int(self.get_parameter('bind_port').get_parameter_value().integer_value)
        self.client_ip = self.get_parameter('client_ip').get_parameter_value().string_value
        self.client_port = int(self.get_parameter('client_port').get_parameter_value().integer_value)
        topic = self.get_parameter('topic').get_parameter_value().string_value

        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.server_socket.bind((bind_ip, bind_port))
        self.get_logger().info(f'UDP bound {bind_ip}:{bind_port} -> {self.client_ip}:{self.client_port}')

        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
        )

        self.subscription = self.create_subscription(ManCtrl,topic, self.on_,msg, qos)
        self.get_logger().info(f"Subscribed to'{topic}' (ugv_msgs/ManCtrl)")

    def _send_udp(self, payload: str, dst: Tuple[str, int]) -> None:
        data = payload.encode()
        self.server_socket.sendto(data, dst)
        self.get_logger().debug(f'UDP {len(data)}B -> {dst}: "{payload}"')

    def on_msg(self, msg: ManCtrl) -> None:
        if msg.auto_en:
            self.get_logger().info('Autonomous Enabled')
            # For later:
            # auto_vel = 0.5
            # steer_cmd = 0.0
            # auto_flag = 1.0
            # self._send_udp(f'{auto_vel}, {steer_cmd}, {auto_flag}', (self.client_ip, self.client_port))
        else:
            if len(msg.arm_cmd) != 5:
                self.get_logger().warn(f"Expected 5 arm_cmd values, got {len(msg.arm_cmd)}")
                return
            payload = f'{msg.arm_cmd[0]}, {msg.arm_cmd[1]}, {msg.arm_cmd[2]}, {msg.arm_cmd[3]}, {msg.arm_cmd[4]}'
            self._send_udp(payload, (self.client_ip, self.client_port))
            self.get_logger().info(
                f'Elbow:{msg.arm_cmd[0]}, Forearm:{msg.arm_cmd[1]}, '
                f'Wrist:{msg.arm_cmd[2]}, Rot Base:{msg.arm_cmd[3]}, Claw:{msg.arm_cmd[4]}'
            )

def main():
    rclpy.init()
    node = UgvControlSub()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        node.server_socket.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
