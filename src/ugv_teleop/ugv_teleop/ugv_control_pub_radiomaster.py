#!/usr/bin/env python3
import time

import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data, qos_profile_system_default
from sensor_msgs.msg import Joy

from ugv_msgs.msg import AutoCtrl, ManCtrl
from ugv_teleop.ugv_arm import ArmController


def clamp(v, lo, hi):
    return max(lo, min(hi, v))


def apply_deadzone(v, dead_zone):
    return 0.0 if abs(v) < dead_zone else v


class UgvControlRadiomasterNode(Node):
    def __init__(self):
        super().__init__('ugv_control_pub_radiomaster')

        self.declare_parameter('dead_zone', 0.05)
        self.declare_parameter('upper_steer_limit', 1.0)
        self.declare_parameter('inc_dec_val', 5.0)
        self.declare_parameter('arm0_lower_limit', 0.0)
        self.declare_parameter('arm0_upper_limit', 170.0)
        self.declare_parameter('arm1_lower_limit', 75.0)
        self.declare_parameter('arm1_upper_limit', 225.0)

        # Radiomaster Pocket defaults.
        # CH1 steer, CH2 throttle, CH3 arm joint 0, CH4 arm joint 1.
        self.declare_parameter('steer_axis', 0)
        self.declare_parameter('throttle_axis', 1)
        self.declare_parameter('arm0_axis', 2)
        self.declare_parameter('arm1_axis', 3)
        self.declare_parameter('steer_sign', 1.0)
        self.declare_parameter('throttle_sign', -1.0)
        self.declare_parameter('arm0_sign', -1.0)
        self.declare_parameter('arm1_sign', 1.0)

        self.dead_zone = float(self.get_parameter('dead_zone').value)
        self.upper_steer_limit = float(self.get_parameter('upper_steer_limit').value)
        self.inc_dec_val = float(self.get_parameter('inc_dec_val').value)
        self.arm0_lo = float(self.get_parameter('arm0_lower_limit').value)
        self.arm0_hi = float(self.get_parameter('arm0_upper_limit').value)
        self.arm1_lo = float(self.get_parameter('arm1_lower_limit').value)
        self.arm1_hi = float(self.get_parameter('arm1_upper_limit').value)
        self.steer_axis = int(self.get_parameter('steer_axis').value)
        self.throttle_axis = int(self.get_parameter('throttle_axis').value)
        self.arm0_axis = int(self.get_parameter('arm0_axis').value)
        self.arm1_axis = int(self.get_parameter('arm1_axis').value)
        self.steer_sign = float(self.get_parameter('steer_sign').value)
        self.throttle_sign = float(self.get_parameter('throttle_sign').value)
        self.arm0_sign = float(self.get_parameter('arm0_sign').value)
        self.arm1_sign = float(self.get_parameter('arm1_sign').value)

        self._last_timer_time = time.monotonic()

        self.man_pub = self.create_publisher(ManCtrl, 'man_ctrl', qos_profile_system_default)
        self.auto_pub = self.create_publisher(AutoCtrl, 'auto_ctrl', qos_profile_system_default)
        self.create_subscription(Joy, 'joy', self.on_joy, qos_profile_sensor_data)

        self.man_obj = ManCtrl()
        self.auto_obj = AutoCtrl()
        self.man_obj.arm_cmd = [0.0, self.arm1_lo]
        self.man_obj.linear_vel = 0.0
        self.man_obj.steer_cmd = 0.0
        self.man_obj.auto_en = False
        self.auto_obj.auto_en = False

        self.cmd_vel = 0.0
        self.cmd_steer = 0.0
        self.arm0_input = 0.0
        self.arm1_input = 0.0

        self.arm_controller = ArmController(
            num_joints=2,
            inc_dec_val=self.inc_dec_val,
            joint0_limits=(self.arm0_lo, self.arm0_hi),
            joint1_limits=(self.arm1_lo, self.arm1_hi),
        )

        self.timer = self.create_timer(0.02, self.timer_callback)
        self.get_logger().info('UGV RADIOMASTER PUBLISHER STARTED AT 50 HZ')

    def timer_callback(self):
        now = time.monotonic()
        dt = max(0.0, min(now - self._last_timer_time, 0.1))
        self._last_timer_time = now

        self.man_obj.linear_vel = self.cmd_vel
        self.man_obj.steer_cmd = clamp(
            self.cmd_steer,
            -self.upper_steer_limit,
            self.upper_steer_limit,
        )

        self.arm_controller.process_arm_control(
            dt=dt,
            ud_pad=self.arm1_input,
            lr_pad=self.arm0_input,
        )
        positions = self.arm_controller.get_positions()
        self.man_obj.arm_cmd = positions

        self.get_logger().info(
            f'PUB RM vel={self.man_obj.linear_vel:.3f}, '
            f'steer={self.man_obj.steer_cmd:.3f}, '
            f'arm=[{positions[0]:.3f},{positions[1]:.3f}]'
        )
        self.man_pub.publish(self.man_obj)

    def on_joy(self, msg: Joy):
        required_axis = max(
            self.steer_axis,
            self.throttle_axis,
            self.arm0_axis,
            self.arm1_axis,
        )
        if len(msg.axes) <= required_axis:
            self.get_logger().warn(
                f'Joy message too small for Radiomaster mapping: '
                f'axes={len(msg.axes)} need>{required_axis}'
            )
            return

        self.cmd_vel = self._read_axis(msg.axes, self.throttle_axis, self.throttle_sign)
        self.cmd_steer = self._read_axis(msg.axes, self.steer_axis, self.steer_sign)
        self.arm0_input = self._read_axis(msg.axes, self.arm0_axis, self.arm0_sign)
        self.arm1_input = self._read_axis(msg.axes, self.arm1_axis, self.arm1_sign)

        self.get_logger().debug(
            f'RM vel={self.cmd_vel:.2f} steer={self.cmd_steer:.2f} '
            f'arm=({self.arm0_input:.2f},{self.arm1_input:.2f})'
        )

    def _read_axis(self, axes, index, sign):
        value = float(axes[index]) * sign
        return apply_deadzone(value, self.dead_zone)

    def destroy_node(self):
        self.get_logger().info('Shutting down ugv_control_pub_radiomaster...')
        super().destroy_node()


def main():
    rclpy.init()
    node = UgvControlRadiomasterNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
