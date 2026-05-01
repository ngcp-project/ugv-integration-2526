#!/usr/bin/env python3
"""Reads CRSF packets from the RadioMaster/ELRS receiver over UART and
publishes them as sensor_msgs/Joy so the existing ugv_control_pub can use them.
"""
import time
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import Joy

import serial

# CRSF framing constants
CRSF_SYNC_BYTES = (0xC8, 0xEE, 0xEA, 0xEC)
CRSF_FRAMETYPE_RC_CHANNELS_PACKED = 0x16
CRSF_MAX_PACKET_LEN = 64

# CRSF raw range to microseconds
CRSF_RAW_MIN = 172
CRSF_RAW_MAX = 1811
US_MIN = 988
US_MAX = 2012


def crc8_dvb_s2(crc, a):
    crc ^= a & 0xFF
    for _ in range(8):
        if crc & 0x80:
            crc = ((crc << 1) ^ 0xD5) & 0xFF
        else:
            crc = (crc << 1) & 0xFF
    return crc


def crc8_buf(buf):
    c = 0
    for b in buf:
        c = crc8_dvb_s2(c, b)
    return c


def raw_to_us(raw):
    return US_MIN + (raw - CRSF_RAW_MIN) * (US_MAX - US_MIN) / (CRSF_RAW_MAX - CRSF_RAW_MIN)


def unpack_channels(payload):
    """Unpack 22 bytes into 16 x 11-bit channel values, then convert to microseconds."""
    if len(payload) < 22:
        return None
    bits = 0
    acc = 0
    channels = []
    for b in payload[:22]:
        acc |= (b & 0xFF) << bits
        bits += 8
        while bits >= 11 and len(channels) < 16:
            channels.append(acc & 0x7FF)
            acc >>= 11
            bits -= 11
    return [raw_to_us(r) for r in channels]


def normalize(us, deadzone):
    """Map a ~988..2012us stick value to [-1.0, 1.0] with deadzone and clamp."""
    center = (US_MIN + US_MAX) / 2.0
    half = (US_MAX - US_MIN) / 2.0
    v = (us - center) / half
    if v > 1.0:
        v = 1.0
    elif v < -1.0:
        v = -1.0
    if abs(v) < deadzone:
        return 0.0
    return v


def switch3_axis(us):
    """3-position switch ~(988/1500/2012) -> -1.0 / 0.0 / 1.0."""
    if us < 1250:
        return -1.0
    if us > 1750:
        return 1.0
    return 0.0


class CrsfJoyNode(Node):
    def __init__(self):
        super().__init__('crsf_joy_node')

        self.declare_parameter('port', '/dev/ttyTHS1')
        self.declare_parameter('baud', 115200)
        self.declare_parameter('deadzone', 0.05)
        self.declare_parameter('debug', False)

        self.port = self.get_parameter('port').value
        self.baud = int(self.get_parameter('baud').value)
        self.deadzone = float(self.get_parameter('deadzone').value)
        self.debug = bool(self.get_parameter('debug').value)

        self.ser = None
        self.buf = bytearray()
        self._last_open_attempt = 0.0
        self._open_retry_s = 2.0

        self.joy_pub = self.create_publisher(Joy, 'joy', qos_profile_sensor_data)

        self._open_serial()

        # Poll serial frequently; publish as packets arrive
        self.timer = self.create_timer(0.005, self._tick)
        self.get_logger().info(
            f'CRSF -> Joy node started on {self.port} @ {self.baud}, deadzone={self.deadzone}'
        )

    def _open_serial(self):
        self._last_open_attempt = time.monotonic()
        try:
            self.ser = serial.Serial(
                self.port, self.baud, timeout=0, write_timeout=0
            )
            self.buf.clear()
            self.get_logger().info(f'Opened serial {self.port} @ {self.baud}')
        except Exception as ex:
            self.ser = None
            self.get_logger().warn(f'Could not open {self.port}: {ex}')

    def _tick(self):
        if self.ser is None:
            if time.monotonic() - self._last_open_attempt > self._open_retry_s:
                self._open_serial()
            return

        try:
            chunk = self.ser.read(256)
        except Exception as ex:
            self.get_logger().warn(f'Serial read failed: {ex}. Reopening.')
            try:
                self.ser.close()
            except Exception:
                pass
            self.ser = None
            return

        if chunk:
            self.buf.extend(chunk)
            self._parse_buffer()

    def _parse_buffer(self):
        # CRSF frame: [addr][len][type][payload...][crc]
        # len byte counts everything AFTER len, i.e. type + payload + crc.
        while len(self.buf) >= 4:
            if self.buf[0] not in CRSF_SYNC_BYTES:
                # resync: drop one byte and try again
                self.buf.pop(0)
                continue

            length = self.buf[1]
            if length < 2 or length > CRSF_MAX_PACKET_LEN:
                # bogus length, resync
                self.buf.pop(0)
                continue

            total = 2 + length  # addr + len + (type..crc)
            if len(self.buf) < total:
                return  # need more bytes

            frame = bytes(self.buf[:total])
            del self.buf[:total]

            ptype = frame[2]
            payload = frame[3:-1]
            crc = frame[-1]
            expected = crc8_buf(frame[2:-1])
            if crc != expected:
                if self.debug:
                    self.get_logger().warn(
                        f'CRC mismatch: got {crc:#x} expected {expected:#x}'
                    )
                continue

            if ptype == CRSF_FRAMETYPE_RC_CHANNELS_PACKED:
                channels = unpack_channels(payload)
                if channels is not None:
                    self._publish_joy(channels)

    def _publish_joy(self, ch):
        # Joy layout expected by ugv_control_pub:
        # axes[1] = -normalize(CH2 pitch), axes[3] = -normalize(CH1 roll)
        # axes[2]/[5] default to 1.0 (trigger released)
        # axes[6]/[7] = 3-pos switches as dpad-style -1/0/1
        # buttons[4] = CH5 (left SA), buttons[5] = CH8 (right SA)
        # axes[2] = LT (arm-enable). CH5 (left SA) high -> trigger "pressed".
        lt_axis = -1.0 if ch[4] > 1500 else 1.0
        axes = [
            0.0,
            -normalize(ch[1], self.deadzone),
            lt_axis,
            -normalize(ch[0], self.deadzone),
            0.0,
            1.0,
            switch3_axis(ch[6]),
            switch3_axis(ch[7]),
        ]
        buttons = [
            0,
            0,
            0,
            0,
            int(ch[4] > 1500),
            int(ch[7] > 1500),
        ]

        msg = Joy()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'radiomaster'
        msg.axes = [float(a) for a in axes]
        msg.buttons = [int(b) for b in buttons]
        self.joy_pub.publish(msg)

        if self.debug:
            self.get_logger().info(
                f'CH us: {[int(c) for c in ch[:8]]} | '
                f'axes={[round(a,2) for a in axes]} buttons={buttons}'
            )

    def destroy_node(self):
        try:
            if self.ser is not None:
                self.ser.close()
        finally:
            super().destroy_node()


def main():
    rclpy.init()
    node = CrsfJoyNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
