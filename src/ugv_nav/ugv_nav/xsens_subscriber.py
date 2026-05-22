#!/usr/bin/env python3
from math import radians, cos, isnan
from typing import Optional, List, Tuple
import argparse
import math

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PointStamped, Vector3Stamped
from std_msgs.msg import Float64
from xsens_mti_ros2_driver.msg import XsStatusWord
from ugv_msgs.msg import ManCtrl


# ---------------------------------------------------------------------------
# Heading convention helpers
#
# xsens compass : N=0, E=90, S=180, W=270 — clockwise-positive, degrees
# math angle    : E=0, N=90               — CCW-positive, radians (Dubins internal)
#
# _compass_to_math_rad(d) = radians(90 - d)
# _math_rad_to_compass(r) = (90 - degrees(r)) % 360
# ---------------------------------------------------------------------------

def _compass_to_math_rad(compass_deg: float) -> float:
    return math.radians(90.0 - compass_deg)


def _math_rad_to_compass(math_rad: float) -> float:
    return (90.0 - math.degrees(math_rad)) % 360.0


# ---------------------------------------------------------------------------
# Dubins path — six path types
# Normalized frame: start at (0,0,alpha), goal at (d,0,beta), radius = 1.
# Each helper returns (t, p, q) in normalized arc-length units, or None.
# ---------------------------------------------------------------------------

def _mod2pi(x: float) -> float:
    return x % (2 * math.pi)


def _LSL(alpha, beta, d):
    sa, ca = math.sin(alpha), math.cos(alpha)
    sb, cb = math.sin(beta),  math.cos(beta)
    p_sq = 2 + d*d - 2*math.cos(alpha - beta) + 2*d*(sa - sb)
    if p_sq < 0:
        return None
    p   = math.sqrt(p_sq)
    tmp = math.atan2(cb - ca, d + sa - sb)
    t   = _mod2pi(-alpha + tmp)
    q   = _mod2pi(beta - tmp)
    return t, p, q


def _RSR(alpha, beta, d):
    sa, ca = math.sin(alpha), math.cos(alpha)
    sb, cb = math.sin(beta),  math.cos(beta)
    p_sq = 2 + d*d - 2*math.cos(alpha - beta) + 2*d*(sb - sa)
    if p_sq < 0:
        return None
    p   = math.sqrt(p_sq)
    tmp = math.atan2(ca - cb, d - sa + sb)
    t   = _mod2pi(alpha - tmp)
    q   = _mod2pi(-beta + tmp)
    return t, p, q


def _LSR(alpha, beta, d):
    sa, ca = math.sin(alpha), math.cos(alpha)
    sb, cb = math.sin(beta),  math.cos(beta)
    p_sq = -2 + d*d + 2*math.cos(alpha - beta) + 2*d*(sa + sb)
    if p_sq < 0:
        return None
    p   = math.sqrt(p_sq)
    tmp = math.atan2(-ca - cb, d + sa + sb) - math.atan2(-2.0, p)
    t   = _mod2pi(-alpha + tmp)
    q   = _mod2pi(-beta + tmp)
    return t, p, q


def _RSL(alpha, beta, d):
    sa, ca = math.sin(alpha), math.cos(alpha)
    sb, cb = math.sin(beta),  math.cos(beta)
    p_sq = -2 + d*d + 2*math.cos(alpha - beta) - 2*d*(sa + sb)
    if p_sq < 0:
        return None
    p   = math.sqrt(p_sq)
    tmp = math.atan2(ca + cb, d - sa - sb) - math.atan2(2.0, p)
    t   = _mod2pi(alpha - tmp)
    q   = _mod2pi(beta - tmp)
    return t, p, q


def _RLR(alpha, beta, d):
    sa, ca = math.sin(alpha), math.cos(alpha)
    sb, cb = math.sin(beta),  math.cos(beta)
    tmp = (6.0 - d*d + 2*math.cos(alpha - beta) + 2*d*(sa - sb)) / 8.0
    if abs(tmp) > 1.0:
        return None
    p = _mod2pi(2*math.pi - math.acos(tmp))
    t = _mod2pi(alpha - math.atan2(ca - cb, d - sa + sb) + _mod2pi(p / 2.0))
    q = _mod2pi(alpha - beta - t + _mod2pi(p))
    return t, p, q


def _LRL(alpha, beta, d):
    sa, ca = math.sin(alpha), math.cos(alpha)
    sb, cb = math.sin(beta),  math.cos(beta)
    tmp = (6.0 - d*d + 2*math.cos(alpha - beta) + 2*d*(-sa + sb)) / 8.0
    if abs(tmp) > 1.0:
        return None
    p = _mod2pi(2*math.pi - math.acos(tmp))
    t = _mod2pi(-alpha - math.atan2(ca - cb, d + sa - sb) + p / 2.0)
    q = _mod2pi(_mod2pi(beta) - alpha - t + _mod2pi(p))
    return t, p, q


def _arc_pts(
    cx: float, cy: float, R: float,
    phi_start: float, delta: float, n: int
) -> List[Tuple[float, float]]:
    return [
        (cx + R * math.cos(phi_start + delta * i / (n - 1)),
         cy + R * math.sin(phi_start + delta * i / (n - 1)))
        for i in range(n)
    ]


def _segment_points(
    x: float, y: float, heading: float,
    seg_type: str, seg_len: float, R: float, spacing: float
) -> Tuple[List[Tuple[float, float]], float, float, float]:
    arc_len = seg_len * R
    if arc_len < 1e-9:
        return [], x, y, heading

    n = max(2, int(arc_len / spacing) + 1)

    if seg_type == 'S':
        pts = [
            (x + (i / (n - 1)) * arc_len * math.cos(heading),
             y + (i / (n - 1)) * arc_len * math.sin(heading))
            for i in range(n)
        ]
        return pts, x + arc_len * math.cos(heading), y + arc_len * math.sin(heading), heading

    if seg_type == 'L':
        cx = x - R * math.sin(heading)
        cy = y + R * math.cos(heading)
        phi0 = math.atan2(y - cy, x - cx)
        pts  = _arc_pts(cx, cy, R, phi0, seg_len, n)
        return pts, cx + R * math.cos(phi0 + seg_len), cy + R * math.sin(phi0 + seg_len), heading + seg_len

    if seg_type == 'R':
        cx = x + R * math.sin(heading)
        cy = y - R * math.cos(heading)
        phi0 = math.atan2(y - cy, x - cx)
        pts  = _arc_pts(cx, cy, R, phi0, -seg_len, n)
        return pts, cx + R * math.cos(phi0 - seg_len), cy + R * math.sin(phi0 - seg_len), heading - seg_len

    return [], x, y, heading


def generate_dubins_path(
    x: float, y: float, theta: float,
    R: float,
    xg: float, yg: float, theta_g: float,
    spacing: float,
) -> List[Tuple[float, float]]:
    """
    Shortest Dubins path from (x, y, theta) to (xg, yg, theta_g).

    All coordinates in local XY (x=east, y=north).
    theta / theta_g in radians, math convention (CCW from +x/east axis).
    R is minimum turning radius in metres.

    Returns waypoints as a list of (x, y) in the same local XY frame.
    """
    dx, dy = xg - x, yg - y
    dist   = math.hypot(dx, dy)
    psi    = math.atan2(dy, dx) if dist > 1e-9 else theta
    d      = dist / R

    alpha = _mod2pi(theta   - psi)
    beta  = _mod2pi(theta_g - psi)

    candidates = [
        ('LSL', _LSL(alpha, beta, d)),
        ('RSR', _RSR(alpha, beta, d)),
        ('LSR', _LSR(alpha, beta, d)),
        ('RSL', _RSL(alpha, beta, d)),
        ('RLR', _RLR(alpha, beta, d)),
        ('LRL', _LRL(alpha, beta, d)),
    ]

    best_type = best_segs = None
    best_len  = float('inf')
    for path_type, segs in candidates:
        if segs is None:
            continue
        total = sum(segs)
        if total < best_len:
            best_len, best_type, best_segs = total, path_type, segs

    if best_type is None:
        raise ValueError("No valid Dubins path found")

    t, p, q = best_segs
    all_points: List[Tuple[float, float]] = []
    cx, cy, ch = x, y, theta

    for i, (seg_char, seg_len) in enumerate(zip(best_type, [t, p, q])):
        pts, cx, cy, ch = _segment_points(cx, cy, ch, seg_char, seg_len, R, spacing)
        all_points.extend(pts if i == 0 else pts[1:])

    if not all_points or math.hypot(all_points[-1][0] - xg, all_points[-1][1] - yg) > 1e-6:
        all_points.append((xg, yg))

    return all_points


# ---------------------------------------------------------------------------
# ROS 2 node
# ---------------------------------------------------------------------------

class XsensLocalXY(Node):
    """
    Converts Xsens GPS fixes to local XY (x=east, y=north, metres relative to
    first fix) and tracks a goal using a Dubins path + pure pursuit controller.

    Heading convention throughout the public API: compass degrees (N=0, E=90, CW).
    Dubins internals use math radians (E=0, N=90, CCW) via the helpers above.

    Equirectangular approximation for lat/lon conversion — accurate to tens of km.
    """

    def __init__(self):
        super().__init__('xsens_local_xy_subscriber')

        self.gps_topic     = self.declare_parameter('gps_topic',     '/filter/positionlla').value
        self.euler_topic   = self.declare_parameter('euler_topic',   '/filter/euler').value
        self.xy_topic      = self.declare_parameter('xy_topic',      '/gnss_local').value
        self.heading_topic = self.declare_parameter('heading_topic', '/xsens/heading_deg').value
        self.frame_id      = self.declare_parameter('frame_id',      'map').value
        self.log_every_fix = self.declare_parameter('log_every_fix', True).value

        # Compass heading = (heading_offset_deg - euler_z) % 360.
        # euler_z is CCW-positive; negating converts to CW. Offset re-zeros North.
        # Field calibration: sensor reads ~30° when pointing North.
        self.heading_offset_deg = float(self.declare_parameter('heading_offset_deg', 30.0).value)

        # Dubins / pure pursuit parameters
        self.min_turn_radius    = float(self.declare_parameter('min_turn_radius',    2.0).value)
        self.point_spacing_m    = float(self.declare_parameter('point_spacing_m',    0.1).value)
        self.lookahead_distance = float(self.declare_parameter('lookahead_distance', 1.5).value)
        self.linear_speed       = float(self.declare_parameter('linear_speed',       0.5).value)
        # Wider tolerance is safer with Float RTK (~0.5m position drift) — prevents
        # the controller from circling forever trying to reach a goal it's already at.
        self.goal_tolerance_m   = float(self.declare_parameter('goal_tolerance_m',   1.5).value)
        self.pursuit_hz         = float(self.declare_parameter('pursuit_hz',         10.0).value)
        # Safety watchdog: force-stop if navigation runs longer than this.
        # Set generously based on expected goal distance / linear_speed.
        self.max_runtime_sec    = float(self.declare_parameter('max_runtime_sec',    30.0).value)

        # Drive command output. ugv_control_sub maps:
        #   steer_cmd in [-1, 1] -> 150..210 deg (so |1.0| = full lock, ~30 deg)
        #   linear_vel in [-1, 1] -> abs(.) * speed_max_cmd (90) — sign is dropped MCU-side
        # max_steering_deg: heading-error magnitude that saturates steering to full lock.
        # max_velocity_mps: m/s value that maps to vel_norm = 1.0; tune to MCU calibration.
        # steering_sign: flip to -1.0 if + heading error steers the wrong way after testing.
        self.cmd_topic         = self.declare_parameter('cmd_topic',         'man_ctrl').value
        self.max_steering_deg  = float(self.declare_parameter('max_steering_deg',  30.0).value)
        self.max_velocity_mps  = float(self.declare_parameter('max_velocity_mps',  1.0).value)
        self.steering_sign     = float(self.declare_parameter('steering_sign',     1.0).value)
        self.arm_park_cmd      = list(self.declare_parameter('arm_park_cmd',  [0.0, 75.0]).value)

        # RTK gating: only set origin once rtk_status >= this value.
        # 0=none, 1=float, 2=fixed. Default 1 accepts float or fixed.
        self.min_rtk_for_origin = int(self.declare_parameter('min_rtk_for_origin', 1).value)
        self.rtk_status = 0
        self._rtk_wait_logged = False

        # GPS / origin state
        self.origin_lat: Optional[float] = None
        self.origin_lon: Optional[float] = None
        self.origin_set   = False
        self.current_x_m  = 0.0
        self.current_y_m  = 0.0

        # Heading state
        self.last_heading_deg = 0.0
        self.heading_received = False

        # Pure pursuit state
        self.dubins_path: List[Tuple[float, float]] = []
        self.last_closest_index = 0
        self.is_navigating      = False
        self.pursuit_timer      = None

        self.xy_pub      = self.create_publisher(PointStamped, self.xy_topic,      10)
        self.heading_pub = self.create_publisher(Float64,       self.heading_topic, 10)
        self.cmd_pub     = self.create_publisher(ManCtrl,       self.cmd_topic,    10)
        self.create_subscription(Vector3Stamped, self.gps_topic,   self.gps_callback,   10)
        self.create_subscription(Vector3Stamped, self.euler_topic, self.euler_callback, 10)
        self.create_subscription(XsStatusWord,   '/status',        self.status_callback, 10)

        self.get_logger().info(
            f"Subscribing GPS: {self.gps_topic}  euler: {self.euler_topic}"
        )

    # -----------------------------------------------------------------------
    # Sensor callbacks
    # -----------------------------------------------------------------------

    def euler_callback(self, msg: Vector3Stamped):
        # msg.vector.z: yaw in degrees, CCW-positive (math convention).
        # Negate to get CW-positive (compass), then apply field offset.
        self.last_heading_deg = (self.heading_offset_deg - msg.vector.z) % 360.0
        self.heading_received = True

        heading_msg = Float64()
        heading_msg.data = self.last_heading_deg
        self.heading_pub.publish(heading_msg)

    def status_callback(self, msg: XsStatusWord):
        self.rtk_status = msg.rtk_status

    def gps_callback(self, msg: Vector3Stamped):
        lat = float(msg.vector.x)
        lon = float(msg.vector.y)

        if isnan(lat) or isnan(lon):
            self.get_logger().warning('Received NaN lat/lon, skipping fix.')
            return

        if not self.origin_set:
            if self.rtk_status < self.min_rtk_for_origin:
                if not self._rtk_wait_logged:
                    self.get_logger().info(
                        f"Waiting for RTK before setting origin "
                        f"(rtk_status={self.rtk_status}, need >={self.min_rtk_for_origin})"
                    )
                    self._rtk_wait_logged = True
                return
            self.origin_lat = lat
            self.origin_lon = lon
            self.origin_set = True
            self.current_x_m = 0.0
            self.current_y_m = 0.0
            self.get_logger().info(
                f"Origin set at rtk_status={self.rtk_status}: "
                f"lat={lat:.8f}, lon={lon:.8f}"
            )
            return

        self.current_x_m, self.current_y_m = self.latlon_to_local_xy(lat, lon)
        self._publish_xy(msg, self.current_x_m, self.current_y_m)

        if self.log_every_fix:
            self.get_logger().info(
                f"GPS: lat={lat:.8f}, lon={lon:.8f} -> "
                f"x={self.current_x_m:.2f} m, y={self.current_y_m:.2f} m, "
                f"heading={self.last_heading_deg:.2f}°"
            )

    def _publish_xy(self, gps_msg: Vector3Stamped, x_m: float, y_m: float):
        point_msg = PointStamped()
        point_msg.header.stamp = gps_msg.header.stamp
        point_msg.header.frame_id = self.frame_id
        point_msg.point.x = x_m
        point_msg.point.y = y_m
        point_msg.point.z = 0.0
        self.xy_pub.publish(point_msg)

    def latlon_to_local_xy(self, lat: float, lon: float) -> Tuple[float, float]:
        if self.origin_lat is None or self.origin_lon is None:
            raise RuntimeError("Origin not set; cannot convert lat/lon to local x/y")
        earth_r = 6378137.0
        dlat = radians(lat) - radians(self.origin_lat)
        dlon = radians(lon) - radians(self.origin_lon)
        x_m  = earth_r * dlon * cos(radians(self.origin_lat))
        y_m  = earth_r * dlat
        return x_m, y_m

    # -----------------------------------------------------------------------
    # Navigation — path planning
    # -----------------------------------------------------------------------

    def start_navigation(
        self,
        target_x_m: float,
        target_y_m: float,
        goal_heading_deg: Optional[float],
    ):
        """
        Generate a Dubins path from the current pose to (target_x_m, target_y_m)
        and start the pure pursuit controller.

        goal_heading_deg: desired arrival heading in compass degrees (N=0, E=90, CW).
            If None, defaults to the bearing from current position toward the goal.
        """
        if goal_heading_deg is None:
            bearing_math_rad = math.atan2(
                target_y_m - self.current_y_m,
                target_x_m - self.current_x_m,
            )
            goal_heading_deg = _math_rad_to_compass(bearing_math_rad)

        start_theta = _compass_to_math_rad(self.last_heading_deg)
        goal_theta  = _compass_to_math_rad(goal_heading_deg)

        self.get_logger().info(
            f"Dubins plan: ({self.current_x_m:.2f}, {self.current_y_m:.2f}) "
            f"hdg={self.last_heading_deg:.1f}° -> "
            f"({target_x_m:.2f}, {target_y_m:.2f}) hdg={goal_heading_deg:.1f}°"
        )

        try:
            self.dubins_path = generate_dubins_path(
                x=self.current_x_m, y=self.current_y_m, theta=start_theta,
                R=self.min_turn_radius,
                xg=target_x_m,      yg=target_y_m,      theta_g=goal_theta,
                spacing=self.point_spacing_m,
            )
        except ValueError as e:
            self.get_logger().error(f"Dubins planning failed: {e}")
            return

        self.get_logger().info(f"Path ready: {len(self.dubins_path)} waypoints.")

        self.last_closest_index = 0
        self.is_navigating      = True
        self.navigation_start_time = self.get_clock().now().nanoseconds / 1e9

        if self.pursuit_timer is not None:
            self.pursuit_timer.cancel()
        self.pursuit_timer = self.create_timer(
            1.0 / self.pursuit_hz, self._pursuit_tick
        )

    # -----------------------------------------------------------------------
    # Navigation — pure pursuit controller
    # -----------------------------------------------------------------------

    def _pursuit_tick(self):
        if not self.is_navigating or not self.dubins_path:
            return

        # Safety watchdog — guarantees the vehicle stops even if it can't reach goal.
        elapsed = self.get_clock().now().nanoseconds / 1e9 - self.navigation_start_time
        if elapsed > self.max_runtime_sec:
            self.get_logger().error(
                f"Runtime watchdog tripped at {elapsed:.1f}s (max={self.max_runtime_sec}s). Stopping."
            )
            self.send_control(0.0, 0.0)
            self.is_navigating = False
            self.pursuit_timer.cancel()
            return

        gx, gy = self.dubins_path[-1]
        dist_to_goal = math.hypot(self.current_x_m - gx, self.current_y_m - gy)

        if dist_to_goal <= self.goal_tolerance_m:
            self.get_logger().info(f"Goal reached. Final dist={dist_to_goal:.3f} m")
            self.send_control(0.0, 0.0)
            self.is_navigating = False
            self.pursuit_timer.cancel()
            return

        if self.last_closest_index >= len(self.dubins_path) - 1:
            self.send_control(0.0, 0.0)
            self.is_navigating = False
            self.pursuit_timer.cancel()
            return

        lookahead, closest_idx = self._find_lookahead_point(
            self.current_x_m, self.current_y_m, self.lookahead_distance
        )
        self.last_closest_index = closest_idx

        # Convert compass heading to math degrees for angle arithmetic
        vehicle_heading_math_deg = 90.0 - self.last_heading_deg
        target_angle_deg = math.degrees(
            math.atan2(lookahead[1] - self.current_y_m,
                       lookahead[0] - self.current_x_m)
        )
        turn_angle_deg = target_angle_deg - vehicle_heading_math_deg
        if turn_angle_deg > 180.0:
            turn_angle_deg -= 360.0
        elif turn_angle_deg < -180.0:
            turn_angle_deg += 360.0

        self.send_control(turn_angle_deg, self.linear_speed)

        if self.log_every_fix:
            self.get_logger().info(
                f"Pursuit: pos=({self.current_x_m:.2f},{self.current_y_m:.2f}) "
                f"lookahead=({lookahead[0]:.2f},{lookahead[1]:.2f}) "
                f"hdg={self.last_heading_deg:.1f}° steer={turn_angle_deg:+.2f}°"
            )

    def _find_lookahead_point(
        self,
        current_x: float,
        current_y: float,
        lookahead_distance: float,
    ) -> Tuple[Tuple[float, float], int]:
        # Find the closest waypoint at or ahead of the last known index
        min_dist      = float('inf')
        closest_index = self.last_closest_index

        for i in range(self.last_closest_index, len(self.dubins_path)):
            px, py = self.dubins_path[i]
            d = math.hypot(px - current_x, py - current_y)
            if d < min_dist:
                min_dist      = d
                closest_index = i

        # Walk forward until accumulated arc length >= lookahead_distance
        accumulated = 0.0
        for i in range(closest_index, len(self.dubins_path) - 1):
            x1, y1 = self.dubins_path[i]
            x2, y2 = self.dubins_path[i + 1]
            seg_len = math.hypot(x2 - x1, y2 - y1)

            if accumulated + seg_len >= lookahead_distance:
                remain = lookahead_distance - accumulated
                ratio  = remain / seg_len if seg_len > 1e-9 else 0.0
                lp = (x1 + ratio * (x2 - x1), y1 + ratio * (y2 - y1))
                return lp, closest_index

            accumulated += seg_len

        return self.dubins_path[-1], closest_index

    def send_control(self, steering_angle_deg: float, velocity: float):
        """
        Publish a ManCtrl message that ugv_control_sub will forward to the
        drive MCU over UDP as "steer_deg,speed_cmd".

        steering_angle_deg: heading error in degrees (positive = left / CCW).
            Saturated to +/- max_steering_deg, then normalized to [-1, 1].
        velocity: forward speed in m/s; 0.0 = stop. Sign is dropped MCU-side.
        """
        steer_norm = self.steering_sign * max(
            -1.0, min(1.0, steering_angle_deg / self.max_steering_deg)
        )
        vel_norm = max(-1.0, min(1.0, velocity / self.max_velocity_mps))

        msg = ManCtrl()
        msg.auto_en = False
        msg.linear_vel = float(vel_norm)
        msg.steer_cmd = float(steer_norm)
        msg.arm_cmd = [float(self.arm_park_cmd[0]), float(self.arm_park_cmd[1])]
        self.cmd_pub.publish(msg)

        self.get_logger().info(
            f"[CONTROL] hdg_err={steering_angle_deg:+.2f}° -> steer={steer_norm:+.3f}, "
            f"v={velocity:.3f} m/s -> vel={vel_norm:+.3f}"
        )

    def destroy_node(self):
        # Best-effort stop before shutdown. Send multiple times with small delays
        # so the MCU has several chances to receive the zero command before this
        # process dies — the MCU has no watchdog and will otherwise keep the last
        # non-zero command running indefinitely.
        import time
        try:
            for _ in range(10):
                self.send_control(0.0, 0.0)
                time.sleep(0.05)
        except Exception:
            pass
        super().destroy_node()

    # -----------------------------------------------------------------------
    # CLI-initiated navigation
    # -----------------------------------------------------------------------

    def process_xy_input(
        self, dx_m: float, dy_m: float, goal_heading_deg: Optional[float] = None
    ):
        """Navigate to (dx_m, dy_m) metres relative to the current position (x=east, y=north)."""
        target_x_m = self.current_x_m + dx_m
        target_y_m = self.current_y_m + dy_m
        self.start_navigation(target_x_m, target_y_m, goal_heading_deg)

    def process_fr_input(
        self, forward_m: float, right_m: float, goal_heading_deg: Optional[float] = None
    ):
        """
        Navigate to a goal specified in the vehicle's body frame at the moment of the call.
        forward_m: metres ahead of the vehicle (negative = behind).
        right_m:   metres to the right of the vehicle (negative = left).

        Converts to global east/north using the current heading, then plans a Dubins path.
        Accuracy depends on heading calibration — a 10° heading error shifts a 20 m
        forward command ~3.5 m sideways.
        """
        theta_rad = _compass_to_math_rad(self.last_heading_deg)
        dx_east  =  forward_m * math.cos(theta_rad) + right_m * math.sin(theta_rad)
        dy_north =  forward_m * math.sin(theta_rad) - right_m * math.cos(theta_rad)
        target_x_m = self.current_x_m + dx_east
        target_y_m = self.current_y_m + dy_north
        self.get_logger().info(
            f"Body-frame goal: fwd={forward_m:.2f} m, right={right_m:.2f} m "
            f"(hdg={self.last_heading_deg:.1f}°) => global ({target_x_m:.2f}, {target_y_m:.2f}) m"
        )
        self.start_navigation(target_x_m, target_y_m, goal_heading_deg)

    def process_latlon_input(
        self, lat: float, lon: float, goal_heading_deg: Optional[float] = None
    ):
        """Navigate to an absolute GPS coordinate."""
        if isnan(lat) or isnan(lon):
            self.get_logger().warning("NaN lat/lon received, skipping.")
            return
        if not self.origin_set:
            raise ValueError("Cannot process lat/lon before a valid GPS fix is received.")
        target_x_m, target_y_m = self.latlon_to_local_xy(lat, lon)
        self.start_navigation(target_x_m, target_y_m, goal_heading_deg)

    # -----------------------------------------------------------------------
    # Startup helpers
    # -----------------------------------------------------------------------

    def wait_for_origin(self, timeout_sec: float = 10.0) -> bool:
        start = self.get_clock().now().nanoseconds / 1e9
        while rclpy.ok():
            rclpy.spin_once(self, timeout_sec=0.1)
            if self.origin_set:
                return True
            if (self.get_clock().now().nanoseconds / 1e9 - start) > timeout_sec:
                return False
        return False

    def wait_for_heading(self, timeout_sec: float = 10.0) -> bool:
        start = self.get_clock().now().nanoseconds / 1e9
        while rclpy.ok():
            rclpy.spin_once(self, timeout_sec=0.1)
            if self.heading_received:
                return True
            if (self.get_clock().now().nanoseconds / 1e9 - start) > timeout_sec:
                return False
        return False


def parse_args(argv=None):
    parser = argparse.ArgumentParser(
        description="Navigate to an XY or lat/lon goal using Dubins path + pure pursuit."
    )
    parser.add_argument(
        "--xy", nargs=2, type=float, metavar=("X", "Y"),
        help="Relative target in metres from current position (x=east, y=north).",
    )
    parser.add_argument(
        "--latlon", nargs=2, type=float, metavar=("LAT", "LON"),
        help="Absolute GPS target.",
    )
    parser.add_argument(
        "--fr", nargs=2, type=float, metavar=("FORWARD", "RIGHT"),
        help="Target in vehicle body frame: metres forward and right of current position. "
             "Negative values go backward / left.",
    )
    parser.add_argument(
        "--heading", type=float, default=None,
        help="Desired arrival heading in compass degrees (N=0, E=90, CW). "
             "Defaults to bearing toward goal if omitted.",
    )
    return parser.parse_args(argv)


def main(args=None):
    import sys
    rclpy.init(args=args)
    cli = parse_args(rclpy.utilities.remove_ros_args(sys.argv)[1:])
    node = XsensLocalXY()

    try:
        if cli.xy is not None or cli.latlon is not None or cli.fr is not None:
            if not node.wait_for_origin(timeout_sec=10.0):
                raise RuntimeError("Timed out waiting for GPS fix.")
            if not node.wait_for_heading(timeout_sec=10.0):
                raise RuntimeError("Timed out waiting for heading from euler topic.")

            if cli.xy is not None:
                node.process_xy_input(cli.xy[0], cli.xy[1], cli.heading)
            elif cli.latlon is not None:
                node.process_latlon_input(cli.latlon[0], cli.latlon[1], cli.heading)
            elif cli.fr is not None:
                node.process_fr_input(cli.fr[0], cli.fr[1], cli.heading)

        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        node.get_logger().error(str(e))
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
