# Claude Workspace History & Reference

> Running log of sessions, decisions, and key workspace knowledge.
> Updated by Claude Code after significant work.

---

## Workspace Overview

**ROS2 UGV (Unmanned Ground Vehicle) workspace** at `/home/ugv/ugv_ros2_ws/src/`

### Packages

| Package | Type | Purpose |
|---|---|---|
| `ugv_msgs` | C++ (CMake) | Custom message definitions |
| `ugv_telemetry` | Python | Converts Xsens data → UDP to GCS |
| `ugv_teleop` | Python | Joystick → robot control via UDP |
| `ntrip` | C++ (CMake) | Standalone NTRIP RTK client |
| `xsens_mti_ros2_driver` | C++ (CMake) | Xsens MTi IMU/GNSS driver |
| `depthai-ros` | C++ (CMake) | OAK-D stereo camera driver |

---

## Custom Messages (`ugv_msgs`)

**`UGVTelemetry.msg`**
```
float32 speed_fps
float32 pitch_deg
float32 yaw_deg
float32 roll_deg
float32 altitude_ft
float64 latitude
float64 longitude
```

**`ManCtrl.msg`**
```
bool auto_en
float32 linear_vel
float32 steer_cmd
float32[5] arm_cmd
```

**`AutoCtrl.msg`**
```
bool auto_en
float32 heading_error
```

---

## Hardware

| Hardware | Interface | Config |
|---|---|---|
| Xsens MTi IMU/GNSS | `/dev/ttyUSB1` @ 921600 baud | `xsens_mti_ros2_driver/param/xsens_mti_node.yaml` |
| OAK-D Camera (Luxonis) | USB 3.0 | `depthai-ros` driver |
| Joystick/Gamepad | `/dev/input/js0` | Standard `joy_node` |

---

## Topic Map

```
Xsens MTi Hardware
 └─(serial)─► xsens_mti_node
                ├── /filter/velocity         (geometry_msgs/Vector3Stamped)
                ├── /filter/euler            (geometry_msgs/Vector3Stamped)
                ├── /filter/positionlla      (geometry_msgs/Vector3Stamped)
                ├── /filter/quaternion
                ├── /imu/data
                ├── /tf
                └── /gnss/fix
                ◄── /rtcm                   (RTK corrections from ntrip_client)

ntrip_client
  ├── subscribes: /nmea
  └── publishes:  /rtcm, /ntrip/diagnostics

xsens_data_conversion
  ├── subscribes: /filter/velocity, /filter/euler, /filter/positionlla
  └── publishes:  /ngcp/telemetry  @ 10 Hz

gcs_telemetry_sender
  ├── subscribes: /ngcp/telemetry
  └── UDP → GCS (192.168.1.100:5005)

joy_node ──► ugv_control_pub ──► man_ctrl, auto_ctrl ──► ugv_control_sub ──► UDP → Robot (192.168.20.21:8)
```

---

## Network Architecture

| Link | Protocol | Address |
|---|---|---|
| Telemetry → GCS | UDP | 192.168.1.100:5005 |
| Commands → Robot firmware | UDP | 192.168.20.21:8 |
| NTRIP RTK corrections | TCP | ntrip.earthscope.org:2101 |

**Telemetry UDP packet** (50 bytes, little-endian):
- Bytes 0-1: reserved
- Bytes 2-5: speed_fps (float32)
- Bytes 6-9: pitch_deg (float32)
- Bytes 10-13: yaw_deg (float32)
- Bytes 14-17: roll_deg (float32)
- Bytes 18-21: altitude_ft (float32)
- Bytes 22-33: reserved
- Bytes 34-41: latitude (float64)
- Bytes 42-49: longitude (float64)

**Control UDP format (CSV text):**
- Manual: `linear_vel,steer_cmd,j0,j1,j2,j3,j4`
- Auto: `auto_vel,steer_cmd,auto_flag,heading_error`

---

## Launch Files

| Launch File | What It Starts |
|---|---|
| `ugv_telemetry/launch/ugv_telemetry.launch.py` | xsens_mti_node + ntrip_client + xsens_data_conversion + gcs_telemetry_sender |
| `ugv_teleop/launch/ugv_control.launch.py` | joy_node + ugv_control_pub + ugv_control_sub |
| `xsens_mti_ros2_driver/launch/xsens_mti_node.launch.py` | Xsens driver standalone |

---

## Key Nodes Reference

| Node | File | Role |
|---|---|---|
| `xsens_data_conversion` | `ugv_telemetry/xsens_data_conversion.py` | Converts Xsens topics → `/ngcp/telemetry` |
| `gcs_telemetry_sender` | `ugv_telemetry/gcs_telemetry_sender.py` | Forwards `/ngcp/telemetry` → GCS via UDP |
| `ugv_control_pub` | `ugv_teleop/ugv_control_pub.py` | Joystick → man_ctrl/auto_ctrl |
| `ugv_control_sub` | `ugv_teleop/ugv_control_sub.py` | man_ctrl/auto_ctrl → robot UDP |
| `ntrip_client` | `ntrip/src/ntrip_client_node.cpp` | NTRIP TCP → /rtcm topic |

---

## NTRIP Notes

- The **Xsens MTi driver has built-in NTRIP support** (`ntrip_util.h/cpp`)
- A **standalone `ntrip` package also exists** in the workspace — reason for duplication unknown
- **Tested 2025 (week prior to 2026-03-20):** NTRIP working through the Xsens node directly
- NTRIP caster: `ntrip.earthscope.org:2101`, mountpoint `CLAR_RTCM3P3`
- Credentials are hardcoded in `ntrip/config/ntrip-param.yaml` — should be moved to env vars

---

## Data Conversions

All telemetry uses **imperial units**:
- Velocity: m/s → ft/s (`sqrt(vx² + vy²) * 3.28084`)
- Altitude: meters → feet (`* 3.28084`)
- Angles: degrees (direct from Xsens euler output)

---

## Teleop / Arm Control

- **5-joint robotic arm** controlled via gamepad
- **LT mode:** Joints 0-3 via D-pad + buttons
- **RT mode:** Joint 4 (end-effector) via A/B
- **Step size:** 5° increments
- **Joint limits:** -360° to +360°
- **Safety:** LB button must be held for motion (`require_safety: True`)
- **Watchdog:** 0.25s timeout → stops motion

---

## Session Log

### 2026-03-20 — Session 1
- Confirmed `gcs_telemetry_sender` node sends to GCS via **UDP only** (not serial)
- Confirmed node does not generate odometry — it only forwards `/ngcp/telemetry`
- Noted that NTRIP works through the Xsens driver directly (tested previous week)
- Standalone `ntrip` package origin unknown — possibly redundant
- Created this `CLAUDE_HISTORY.md` for ongoing workspace documentation

### 2026-03-20 — Session 2
- Tested GCS telemetry pipeline indoors without XBees or real hardware
- Test method: `ros2 topic pub /ngcp/telemetry` → `gcs_telemetry_sender` (pointed at 127.0.0.1) → `gcs_udp_listener.py`
- Confirmed UDP packet sends and decodes correctly
- Confirmed `xsens_data_conversion` speed conversion is correct: `sqrt(vx² + vy²) * 3.28084` (horizontal speed only, intentional for ground vehicle)
- Renamed `telemetry_sub` → `gcs_telemetry_sender` (file, class, node name, setup.py, launch file)
- Renamed `udp_listener.py` → `gcs_udp_listener.py`
- Rebuild required: `colcon build --packages-select ugv_telemetry`
