#!/usr/bin/env python3
import time
import rclpy
from rclpy.node import Node
from ugv_msgs.msg import ManCtrl, AutoCtrl
from sensor_msgs.msg import Joy
from rclpy.qos import qos_profile_system_default, qos_profile_sensor_data
from ugv_teleop.ugv_arm import ArmController

def clamp(v, lo, hi):
    return max(lo, min(hi, v))

class UgvControlNode(Node):
    def __init__(self):
        super().__init__('ugv_control_pub')

        self.declare_parameter('max_joy_val', float(2**15))
        self.declare_parameter('dead_zone', 0.15)
        self.declare_parameter('upper_steer_limit', 1.0)
        self.declare_parameter('inc_dec_val', 5.0)
        self.declare_parameter('lower_elbow_limit', -360.0)
        self.declare_parameter('upper_elbow_limit', 360.0)

        '''Newly added params/constants'''
        self.declare_parameter('watchdog_timeout', 0.25) # seconds without /joy → stop (4 Hz)
        # self.declare_parameter('publish_rate_hz', 50.0) # 50 Hz main loop
        self.declare_parameter('require_safety', True) # require LB held to allow motion

        # Retrieve parameter values
        self.max_joy_val       = self.get_parameter('max_joy_val').value
        self.dead_zone         = self.get_parameter('dead_zone').value
        self.upper_steer_limit = self.get_parameter('upper_steer_limit').value
        self.inc_dec_val       = self.get_parameter('inc_dec_val').value
        self.lower_elbow_limit = self.get_parameter('lower_elbow_limit').value
        self.upper_elbow_limit = self.get_parameter('upper_elbow_limit').value
        # self.watchdog_timeout = self.get_parameter('watchdog_timeout').value
        # self.require_safety  = self.get_parameter('require_safety').value
        self.last_joy_time = time.monotonic()
        self._last_timer_time = time.monotonic()

        self.man_pub = self.create_publisher(ManCtrl, 'man_ctrl', qos_profile_system_default)
        # replaced depth=10 wtih qos profile sys default, built into ros2. lower latency
        self.auto_pub = self.create_publisher(AutoCtrl, 'auto_ctrl', qos_profile_system_default)
        self.create_subscription(Joy, 'joy', self.on_joy, qos_profile_sensor_data)
        self.get_logger().info('UGV Publisher Started! (50hz)')

        # Joy is the standard for getting gamepad input in ROS2. Built in feature.
        # Published by a node that reads controller input thru OS.

        self.man_obj = ManCtrl()
        self.auto_obj = AutoCtrl()
        self.man_obj.arm_cmd = [0.0] * 5
        self.man_obj.linear_vel = 0.0
        self.man_obj.steer_cmd = 0.0
        self.man_obj.auto_en = False
        self.auto_obj.auto_en = False

        self.cmd_vel = 0.0
        self.cmd_steer = 0.0
        self.l_bumper = 0
        self.r_bumper = 0
        self.ud_dpad = 0
        self.lr_dpad = 0
        self.a_btn = 0
        self.b_btn = 0
        self.x_btn = 0
        self.y_btn = 0

        self.lt_val = 0
        self.rt_val = 0

        # Arm controller
        self.arm_controller = ArmController(num_joints=5, inc_dec_val=float(self.inc_dec_val))
        # self.man_obj.arm_cmd = [0.0] * 5

        self.timer = self.create_timer(0.02, self.timer_callback) # 50hz since 1/50 = 0.02

        # self._stop = threading.Event()
        # self.reader_thread = threading.Thread(target=self.on_joy, daemon=True)
        # self.reader_thread.start()

        self.get_logger().info('UGV CONTROL PUBLISHER STARTED AT 50 HZ')

# Stop function used by watchdog and error handlers
    # def _stop(self, reason: str) -> None:
    #     self.man_obj.linear_vel = 0.0
    #     self.man_obj.steer_cmd = 0.0
    #     self.man_pub.publish(self.man_obj)
    #     self.auto_pub.publish(self.auto_obj)
    #     self.get_logger().warn(f'[SAFETY STOP]: {reason}')

    def timer_callback(self):
        now = time.monotonic() # get curr time
        dt = now - self._last_timer_time
        self._last_timer_time = now
        dt = max(0.0, min(dt, 0.1))

        self.man_obj.linear_vel = self.cmd_vel
        self.man_obj.steer_cmd = clamp(
                self.cmd_steer,
                -self.upper_steer_limit, self.upper_steer_limit
            )

        # if self.l_bumper == 1 and self.r_bumper == 1 and self.a_btn == 1:
        #     self.man_obj.auto_en = not self.man_obj.auto_en
        #     self.auto_obj.auto_en = self.man_obj.auto_en

        # if self.man_obj.auto_en:
        #     self.man_pub.publish(self.man_obj)
        #     self.auto_pub.publish(self.auto_obj)
        #     return

        # Constants for lt and rt on controller
        LT_ON = self.lt_val > 1000
        RT_ON = self.rt_val > 1000

        if LT_ON and not RT_ON: # only left trigger is on:
            self.arm_controller.process_left_trigger_mode(
                dt=dt,
                ud_pad=self.ud_dpad,
                lr_pad=self.lr_dpad,
                a_btn=self.a_btn,
                b_btn=self.b_btn,
                x_btn=self.x_btn,
                y_btn=self.y_btn
            )

        elif RT_ON and not LT_ON: # only right trigger is on:
        # If you're using num_joints=5, this controls joint 4 (index 4)
            self.arm_controller.process_right_trigger_mode(
                dt=dt,
                a_btn=self.a_btn,
                b_btn=self.b_btn
            )
        else:
            pass

        positions = self.arm_controller.get_positions()
        self.man_obj.arm_cmd = positions[:len(self.man_obj.arm_cmd)]

        self.man_pub.publish(self.man_obj) # publish everything.

    # converted to joy msgs
    def on_joy(self, msg: Joy): # replaced gamepad reader function
            self.last_joy_time = time.monotonic()

            if len(msg.axes) < 8 or len(msg.buttons) < 6:
                self.get_logger().warn(
                    f"Joy message too small: axes={len(msg.axes)} buttons={len(msg.buttons)}"
                )
                return

            # try:
                # Axes/buttons mapping depends on your controller
            self.cmd_vel   = -msg.axes[1]
            self.cmd_steer = -msg.axes[3]


            # Deadzone filtering added
            # if abs(self.cmd_vel) < self.dead_zone:
            #     self.cmd_vel = 0.0
            # if abs(self.cmd_steer) < self.dead_zone:
            #     self.cmd_steer = 0.0

            self.lt_val = int((1 - msg.axes[2]) * self.max_joy_val / 2)  # normalized [0, 32768]
            self.rt_val = int((1 - msg.axes[5]) * self.max_joy_val / 2)
            self.get_logger().debug(f"lt_val={self.lt_val} rt_val={self.rt_val}")
            self.l_bumper  = int(msg.buttons[4])
            self.r_bumper  = int(msg.buttons[5])
            self.a_btn     = int(msg.buttons[0])
            self.b_btn     = int(msg.buttons[1])
            self.x_btn     = int(msg.buttons[2])
            self.y_btn     = int(msg.buttons[3])
            self.lr_dpad   = int(msg.axes[6])
            self.ud_dpad   = int(msg.axes[7])

            # left_x  = msg.axes[0]
            # left_y  = msg.axes[1]
            # right_x = msg.axes[3]

            self.get_logger().info(f"cmd_vel={self.cmd_vel:.2f}, cmd_steer={self.cmd_steer:.2f}")


    # Shutdown function
    def destroy_node(self):
        self.get_logger().info('Shutting down node..')
        # self._stop('Node shutdown')
        super().destroy_node()

def main():
    rclpy.init()
    node = UgvControlNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
