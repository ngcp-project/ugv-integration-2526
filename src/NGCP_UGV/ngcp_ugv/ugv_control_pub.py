#!/usr/bin/env python3
import threading
# import time
import rclpy
from rclpy.node import Node
from ugv_msgs.msg import ManCtrl, AutoCtrl
# from inputs import get_gamepad
from sensor_msgs.msg import Joy
from rclpy.qos import qos_profile_system_default, qos_profile_sensor_data

# MAX_JOY_VAL = float(2**15)  # 32768.0
# DEAD_ZONE_THRESH = 0.15
# UPPER_STEER_CMD_LIMIT = 1.0
# INC_DEC_VAL = 5.0

# LOWER_ELBOW_SERV_LIM = -360.0
# UPPER_ELBOW_SERV_LIM = 360.0

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

        # Retrieve parameter values
        self.max_joy_val       = self.get_parameter('max_joy_val').value
        self.dead_zone         = self.get_parameter('dead_zone').value
        self.upper_steer_limit = self.get_parameter('upper_steer_limit').value
        self.inc_dec_val       = self.get_parameter('inc_dec_val').value
        self.lower_elbow_limit = self.get_parameter('lower_elbow_limit').value
        self.upper_elbow_limit = self.get_parameter('upper_elbow_limit').value

        self.man_pub = self.create_publisher(ManCtrl, 'man_ctrl', qos_profile_system_default)
        # replaced depth=10 wtih qos profile sys default, built into ros2. lower latency
        self.auto_pub = self.create_publisher(AutoCtrl, 'auto_ctrl', qos_profile_system_default)
        self.create_subscription(Joy, 'joy', self.on_joy, qos_profile_sensor_data)
        self.get_logger().info('UGV Publiser Started (joy topic)')

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
        self.lt_val = 0
        self.rt_val = 0
        self.ud_dpad = 0
        self.lr_dpad = 0
        self.a_btn = 0
        self.b_btn = 0
        self.x_btn = 0
        self.y_btn = 0

        self.timer = self.create_timer(0.02, self.timer_callback)

        # self._stop = threading.Event()
        # self.reader_thread = threading.Thread(target=self._gamepad_reader, daemon=True)
        # self.reader_thread.start()

        self.get_logger().info('UGV CONTROL PUBLISHER STARTED AT 50 HZ')

    def timer_callback(self):
        if self.l_bumper == 1 and self.r_bumper == 1 and self.a_btn == 1:
            self.man_obj.auto_en = not self.man_obj.auto_en
            self.auto_obj.auto_en = self.man_obj.auto_en

        if self.man_obj.auto_en:
            self.man_pub.publish(self.man_obj)
            self.auto_pub.publish(self.auto_obj)
            return

        if self.lt_val > 1000 and self.rt_val < 1000:
            self.man_obj.arm_cmd[1] += float(self.ud_dpad) * self.inc_dec_val
            self.man_obj.arm_cmd[1] = clamp(self.man_obj.arm_cmd[1],
                                           self.lower_elbow_limit, self.upper_elbow_limit)

            self.man_obj.arm_cmd[0] += float(self.lr_dpad) * self.inc_dec_val
            self.man_obj.arm_cmd[0] = clamp(self.man_obj.arm_cmd[0], -360.0, 360.0)

            if self.a_btn or self.b_btn:
                self.man_obj.arm_cmd[2] += float(self.a_btn) * self.inc_dec_val
                self.man_obj.arm_cmd[2] -= float(self.b_btn) * self.inc_dec_val

            if self.x_btn or self.y_btn:
                self.man_obj.arm_cmd[3] += float(self.x_btn) * self.inc_dec_val
                self.man_obj.arm_cmd[3] -= float(self.y_btn) * self.inc_dec_val

        elif self.rt_val > 1000 and self.lt_val < 1000:
            self.man_obj.arm_cmd[4] += float(self.a_btn) * self.inc_dec_val
            self.man_obj.arm_cmd[4] -= float(self.b_btn) * self.inc_dec_val

        else:
            self.man_obj.linear_vel = self.cmd_vel
            self.man_obj.steer_cmd = clamp(self.cmd_steer,
                                           -self.upper_elbow_limit, self.upper_elbow_limit)

        self.man_pub.publish(self.man_obj)

    # converted to joy msgs 
    def on_joy(self, msg: Joy): # replaced gamepad reader function
            # Axes/buttons mapping depends on your controller
            self.cmd_vel   = -msg.axes[1]
            self.cmd_steer =  msg.axes[3]
            self.lt_val    = int((1 - msg.axes[2]) * self.max_joy_val / 2)  # normalized [0, 32767]
            # changed hard coded 32737 # to default value
            self.rt_val    = int((1 - msg.axes[5]) * self.max_joy_val / 2)
            self.l_bumper  = int(msg.buttons[4])
            self.r_bumper  = int(msg.buttons[5])
            self.a_btn     = int(msg.buttons[0])
            self.b_btn     = int(msg.buttons[1])
            self.x_btn     = int(msg.buttons[2])
            self.y_btn     = int(msg.buttons[3])
            # d-pad is usually axes[6], axes[7]
            self.lr_dpad   = int(msg.axes[6])
            self.ud_dpad   = int(msg.axes[7])

    #  def _gamepad_reader(self):
    #     while not self._stop.is_set():
    #         try:
    #             events = get_gamepad()
    #             for e in events:
    #                 code = e.code
    #                 state = e.state

    #                 if code == 'ABS_Y':
    #                     val = -state / MAX_JOY_VAL
    #                     if abs(val) < DEAD_ZONE_THRESH:
    #                         val = 0.0
    #                     self.cmd_vel = float(val)

    #                 elif code == 'ABS_RX':
    #                     val = state / MAX_JOY_VAL
    #                     if abs(val) < DEAD_ZONE_THRESH:
    #                         val = 0.0
    #                     self.cmd_steer = float(val)

    #                 elif code == 'ABS_Z':
    #                     self.lt_val = int(state)

    #                 elif code == 'ABS_RZ':
    #                     self.rt_val = int(state)

    #                 elif code == 'ABS_HAT0Y':
    #                     self.ud_dpad = int(state)

    #                 elif code == 'ABS_HAT0X':
    #                     self.lr_dpad = int(state)

    #                 elif code == 'BTN_TR':
    #                     self.r_bumper = int(state)

    #                 elif code == 'BTN_TL':
    #                     self.l_bumper = int(state)

    #                 elif code == 'BTN_SOUTH':
    #                     self.a_btn = int(state)

    #                 elif code == 'BTN_EAST':
    #                     self.b_btn = int(state)

    #                 elif code == 'BTN_NORTH':
    #                     self.x_btn = int(state)

    #                 elif code == 'BTN_WEST':
    #                     self.y_btn = int(state)

    #         except KeyboardInterrupt:
    #             break
    #         except Exception as ex:
    #             self.get_logger().warning(f'GAMEPAD READ EXCEPTION: {ex}')
    #             time.sleep(0.01)

    def destroy_node(self):
        self.get_logger().info('Shutting down node..')
        super().destroy_node()

def main():
    rclpy.init()
    node = UgvControlNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        # node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
