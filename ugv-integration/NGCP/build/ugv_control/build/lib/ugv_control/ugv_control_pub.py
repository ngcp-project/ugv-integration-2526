#!/usr/bin/env python3
import threading
import time

import rclpy
from rclpy.node import Node
from ugv_msgs.msg import ManCtrl, AutoCtrl
from inputs import get_gamepad

MAX_JOY_VAL = float(2**15)  # 32768.0
DEAD_ZONE_THRESH = 0.15
UPPER_STEER_CMD_LIMIT = 1.0
INC_DEC_VAL = 5.0

LOWER_ELBOW_SERV_LIM = -360.0
UPPER_ELBOW_SERV_LIM = 360.0

def clamp(v, lo, hi):
    return max(lo, min(hi, v))

class UgvControlNode(Node):
    def __init__(self):
        super().__init__('ugv_control_pub')

        self.man_pub = self.create_publisher(ManCtrl, 'man_ctrl', 10)
        self.auto_pub = self.create_publisher(AutoCtrl, 'auto_ctrl', 10)

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

        self._stop = threading.Event()
        self.reader_thread = threading.Thread(target=self._gamepad_reader, daemon=True)
        self.reader_thread.start()

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
            self.man_obj.arm_cmd[1] += float(self.ud_dpad) * INC_DEC_VAL
            self.man_obj.arm_cmd[1] = clamp(self.man_obj.arm_cmd[1],
                                            LOWER_ELBOW_SERV_LIM, UPPER_ELBOW_SERV_LIM)

            self.man_obj.arm_cmd[0] += float(self.lr_dpad) * INC_DEC_VAL
            self.man_obj.arm_cmd[0] = clamp(self.man_obj.arm_cmd[0], -360.0, 360.0)

            if self.a_btn or self.b_btn:
                self.man_obj.arm_cmd[2] += float(self.a_btn) * INC_DEC_VAL
                self.man_obj.arm_cmd[2] -= float(self.b_btn) * INC_DEC_VAL

            if self.x_btn or self.y_btn:
                self.man_obj.arm_cmd[3] += float(self.x_btn) * INC_DEC_VAL
                self.man_obj.arm_cmd[3] -= float(self.y_btn) * INC_DEC_VAL

        elif self.rt_val > 1000 and self.lt_val < 1000:
            self.man_obj.arm_cmd[4] += float(self.a_btn) * INC_DEC_VAL
            self.man_obj.arm_cmd[4] -= float(self.b_btn) * INC_DEC_VAL

        else:
            self.man_obj.linear_vel = self.cmd_vel
            self.man_obj.steer_cmd = clamp(self.cmd_steer,
                                           -UPPER_STEER_CMD_LIMIT, UPPER_STEER_CMD_LIMIT)

        self.man_pub.publish(self.man_obj)

    def _gamepad_reader(self):
        while not self._stop.is_set():
            try:
                events = get_gamepad()
                for e in events:
                    code = e.code
                    state = e.state

                    if code == 'ABS_Y':
                        val = -state / MAX_JOY_VAL
                        if abs(val) < DEAD_ZONE_THRESH:
                            val = 0.0
                        self.cmd_vel = float(val)

                    elif code == 'ABS_RX':
                        val = state / MAX_JOY_VAL
                        if abs(val) < DEAD_ZONE_THRESH:
                            val = 0.0
                        self.cmd_steer = float(val)

                    elif code == 'ABS_Z':
                        self.lt_val = int(state)

                    elif code == 'ABS_RZ':
                        self.rt_val = int(state)

                    elif code == 'ABS_HAT0Y':
                        self.ud_dpad = int(state)

                    elif code == 'ABS_HAT0X':
                        self.lr_dpad = int(state)

                    elif code == 'BTN_TR':
                        self.r_bumper = int(state)

                    elif code == 'BTN_TL':
                        self.l_bumper = int(state)

                    elif code == 'BTN_SOUTH':
                        self.a_btn = int(state)

                    elif code == 'BTN_EAST':
                        self.b_btn = int(state)

                    elif code == 'BTN_NORTH':
                        self.x_btn = int(state)

                    elif code == 'BTN_WEST':
                        self.y_btn = int(state)

            except KeyboardInterrupt:
                break
            except Exception as ex:
                self.get_logger().warning(f'GAMEPAD READ EXCEPTION: {ex}')
                time.sleep(0.01)

    def destroy_node(self):
        self._stop.set()
        try:
            if self.reader_thread.is_alive():
                self.reader_thread.join(timeout=1.0)
        except Exception:
            pass
        super().destroy_node()

def main():
    rclpy.init()
    node = UgvControlNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
