
import threading
import time

import rclpy
from rclpy.node import Node
from ugv_msgs.msg import ManCtrl, Auto Ctrl
from inputs import get_gamepad

SCALE_FACTOR = -32700
MAX_JOY_VAL = 2**15 # max input of 32,768
LOWER_ELBOW_SERV_LIM = -360.0
UPPER_ELBOW_SERV_LIM = 360.0 
DEAD_ZONE_THRESH = 15/100
UPPER_STEER_CMD_LIMIT = 1.0 
INC_DEC_VAL = 5.0

class UgvControlNode(Node): # publisher node
    def __init__(self):
            super().__init__('ugv_control_node')

            #Publishers:
            self.man_pub = self.create_publisher(ManCtrl, 'man_ctrl', 10)
            self.auto_pub = self.create_publisher(AutoCtrl, 'auto_ctrl', 10)

            #Message instances:
            self.man_obj = ManCtrl()
            self.auto_obj = AutoCtrl()
            self.man_obj.arm_cmd = [0.0]*5
            self.man_obj.linear_vel = 0.0
            self.man_obj.steer_cmd = 0.0
            self.man_obj.auto_en = False
            self.auto_obj.auto_en = False

            #State from joystick
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

            #50 Hz timer (20 ms)
            self.timer = self.create_timer(0.02, self.timer_callback)

            #start gamepad reader thread
            self._stop = threading.Event()
            self.reader_thread = threading.Thread(target=self._gamepad_reader, daemon=True)
            self.reader_thread.start()

            self.get_logger().info("UGV CONTROL NODE STARTED AT 50 HZ")

      #timer callback
      def timer_callback(self):
            #latch autonomous toggles when LB + RB + A are pressed
            if self.l_bumper == 1 and self.r_bumper == 1 and self.a_btn == 1:
                  self.man_obj.auto_en = not self.man_obj.auto_en
                  self.auto_obj.auto_en = self.man_obj.auto_en  #to keep in sync

            if self.man_obj.auto_en:
                  self.get_logger().debug("Autonomous Mode Enabled")
                  #publish both
                  self.man_pub.publish(self.man_obj)
                  self.auto_pub.publishe(self.auto_obj)

            #manual mode behavior
            if self.lt_val > 1000 and self.rt_val < 1000:
                #left trigger held
                self.man_obj.arm_cmd[1] += self.ud_dpab * INC_DEC_VAL
                self.man_obj.arm_cmd[1] = max(LOWER_ELBOW_SERV_LIM, min(UPPER_ELBOW_SERV_LIM, self.man_obj.arm_cmd[1]))
                self.man_obj.arm_cmd[0] += self.lr_dpad * INC_DEC_VAL
                self.man_obj.arm_cmd[0] = max(-360.0, min(360.0, self.man_obj.arm_cmd[0]))

                if self.a_btn == 1 or self.b_btn == 1:
                        self.man_obj.arm_cmd[2] += float(self.a_btn) * INC_DEC_VAL
                        self.man_obj.arm_cmd[2] -= float(self.b_btn) * INC_DEC_VAL

                if self.x_btn == 1 or self.y_btn == 1:
                        self.man_obj.arm_cmd[3] += float(self.x_btn) * INC_DEC_VAL
                        self.man_obj.arm_cmd[3] -= float(self.y_btn) * INC_DEC_VAL

                elif self.rt_val > 1000 and self.lt_val < 1000:
                      #right trigger held
                      self.man_obj.arm_cmd[4] += float(self.a_btn) * INC_DEC_VAL
                      self.man_obj.arm_cmd[4] -=float (self.b_btn) * INC_DEC_VAL

                else:
                      #drive commands
                      self.man_obj.liear_vel = self.cmd_vel
                      #clamp steer
                      steer = self.cmd_steer
                      if steer > UPPER_STEER_CMD_LIMIT:
                            steer = UPPER_STEER_CMD_LIMIT
                      if steer < -UPPER_STEER_CMD_LIMIT:
                            steer = -UPPER_STEER_CMD_LIMIT
                      self.man_obj.steer_cmd = steer

                #always publish man_ctrl
                self.man_pub.publish(self.man_obj)

      #gamepad reader
      def _gamepad_reader(self):
            #keep reading events and updating shared state
            while not self._stop.is_set():
                  try:
                        event_list = get_gamepad()    #blocks until an input arrives
                        if not event_list:
                              continue
                        e = event_list:
                        code = e.code
                        state = e.state

                        if code == "ABS_Y":
                              val = state / float(MAX_JOY_VAL)
                              if -DEAD_ZONE_THRESH <= val <= DEAD_ZONE_THRESH:
                                    val = 0.0
                              self.cmd_steer = val

                        elif code == "ABS_RX":
                              val = state / float(-MAX_JOY_VAL)
                              if -DEAD_ZONE_THRESH <= val <= DEAD_ZONE_THRESH:
                                          val = 0.0
                              self.cmd_steer = val
                              
                        elif code == "ABS_Z":
                              self.lt_val = state

                        elif code == "ABS_RZ":
                                    elf.rt_val = state  

                        elif code == "ABS_HAT0Y":
                              self.ud_dpad = state   

                        elif code == "ABS_HAT0X":
                              self.lr_dpad = state    

                        elif code == 'BTN_TR':
                              self.r_bumper = state
                              self.get_loggr().debug("Right bumper action")

                        elif code == 'BTN_TL':
                              self.l_bumper = state                       
                              self.get_logger().debug("Left bumper action")

                        elif code == "BTN_SOUTH":     #A
                              self.a_btn = state

                        elif code == "BTN_EAST":      #B
                              self.b_btn = state

                        elif code == "BTN_NORTH":     #X
                              self.x_btn = state

                        elif code == "BTN_WEST":      #Y
                              self.y_btn = state

                  except KeyboardInterrupt:
                        break
                  except Exception as ex:
                        self.get_logger().warn(f"GAMEPAD READ EXCEPTION: {ex}")
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
      node = UGVControlNode()
      try: 
            #multithreaded to allow time + reader thread callbacks, though reader is external
            rclpy.spin(node)
      except KeyboardInterrupt:
            pass
      finally:
            node.destroy_node()
            rclpy.shutdown()                


if __name__ == "__main__":
      main()