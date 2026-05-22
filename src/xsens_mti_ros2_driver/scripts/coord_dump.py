import os
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import Vector3Stamped

class CoordDumper(Node):
    def __init__(self):
        super().__init__('coord_dumper')

        self.gnss_sub = self.create_subscription(
            NavSatFix, '/gnss', self.gnss_callback, 10
        )
        self.euler_sub = self.create_subscription(
            Vector3Stamped, '/filter/euler', self.euler_callback, 10
        )

        self.count = 0
        self.latest_z = None

        open('ntrip_coords.txt', 'w').close()
        self.get_logger().info('coord_dumper started')

    def euler_callback(self, msg):
        self.latest_z = msg.vector.z

    def gnss_callback(self, msg):
        if msg.status.status < 0:
            self.get_logger().warn('No GNSS fix yet, skipping...')
            return

        if self.latest_z is None:
            self.get_logger().warn('No euler data yet, skipping...')
            return

        with open('ntrip_coords.txt', 'a') as f:
            f.write(f"{msg.latitude}, {msg.longitude}, {self.latest_z}\n")

        self.count += 1
        self.get_logger().info(
            f"Saved sample {self.count}: "
            f"{msg.latitude}, {msg.longitude}, {self.latest_z}"
        )

        if self.count >= 3:
            self.get_logger().info('Collected 3 valid samples, shutting down')
            os._exit(0)

def main():
    rclpy.init()
    node = CoordDumper()
    rclpy.spin(node)
    node.destroy_node()

if __name__ == '__main__':
    main()
