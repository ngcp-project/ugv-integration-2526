

  Before any command-specific logic, every command follows this chain:

  1. GCS calls SendCommand(cmd, Vehicle.MRA) → puts the command on CommandQueue
  2. GCS GCSXBee.RunCommandThread pulls from CommandQueue → calls cmd.EncodePacket() to
  serialize to bytes → calls xbee.transmit_data() to send over the radio to the Jetson's
  MAC address
  3. Jetson VehicleXBee.RunCommandThread is blocking on xbee.retrieve_data() → receives raw
   bytes from the XBee radio → puts the raw frame on CommandQueue
  4. Jetson xbee_command_receiver._command_loop calls ReceiveCommand(DecodeFormat.Class) →
  pulls from CommandQueue → reads the first byte (command ID) → calls the matching
  DecodePacket() to deserialize into a Python object
  5. Jetson _dispatch(command) routes based on the command type

  After dispatch, every command calls _reply_telemetry() which:

  6. Reads COMMAND_ID and PacketID from the command that was just received
  7. Grabs the latest Xsens sensor data from _latest_telemetry (if available)
  8. Creates a Telemetry object with the echoed IDs + sensor data
  9. Calls SendTelemetry(telem) → puts on TelemetryQueue
  10. Jetson VehicleXBee.RunTelemetryThread pulls from TelemetryQueue → calls
  telem.Encode() → serializes to 72 bytes → xbee.transmit_data() sends to GCS MAC address
  11. GCS GCSXBee.RunTelemetryThread receives the bytes → calls Telemetry.Decode() → puts
  the decoded Telemetry object on TelemetryQueue
  12. GCS app calls ReceiveTelemetry() → pulls from queue → sees CommandID matching what it
   sent → knows the Jetson acknowledged

  ---
  Command 1 — Heartbeat

  What the GCS sends:
  Format: "BIH" (7 bytes)
  Byte 0:     CommandID = 1
  Bytes 1-4:  PacketID (auto-incrementing counter)
  Bytes 5-6:  ConnectionStatus (0=Connected, 1=Unstable, 2=Disconnected)

  What happens on the Jetson:
  1. _dispatch matches isinstance(command, Heartbeat)
  2. Logs: [CMD 1] Heartbeat — status: Connected
  3. Calls _reply_telemetry(command) with no extra flags
  4. The telemetry reply is built with CommandID=1, the same PacketID, and the latest
  sensor data (speed, pitch, yaw, roll, altitude, GPS position)

  What the GCS learns from the reply:
  - The vehicle is alive and responding
  - CommandID=1 confirms this is a heartbeat response
  - The sensor data gives the GCS the vehicle's current state

  What happens if no reply comes back:
  - The GCS knows the vehicle is offline or the XBee link is broken

  ---
  Command 2 — EmergencyStop

  What the GCS sends:
  Format: "BIB" (6 bytes)
  Byte 0:     CommandID = 2
  Bytes 1-4:  PacketID
  Byte 5:     StopStatus (0=ACTIVATE e-stop, 1=RELEASE e-stop)

  What happens on the Jetson:
  1. _dispatch matches isinstance(command, EmergencyStop)
  2. Checks command.StopStatus:
    - 0 → e-stop is ACTIVATED (stop everything)
    - 1 → e-stop is RELEASED (resume operation)
  3. Logs: [CMD 2] EmergencyStop — ACTIVATE or RELEASE
  4. Creates a Bool message with data = True (activate) or data = False (release)
  5. Publishes to /ngcp/estop ROS topic
  6. Any node subscribed to /ngcp/estop (like ugv_control_sub) should read this and either
  kill the motors or resume. Note: ugv_control_sub does NOT currently subscribe to
  /ngcp/estop — this is a gap that needs wiring up.
  7. Calls _reply_telemetry(command) → sends telemetry back with CommandID=2

  What the GCS learns from the reply:
  - CommandID=2 confirms the e-stop command was received and processed
  - Sensor data shows whether the vehicle actually stopped

  ---
  Command 3 — AddZone

  What the GCS sends:
  Format: "=BIHB" + N×"dd" (8 + 16×N bytes, where N = 3 to 6 coordinate pairs)
  Byte 0:     CommandID = 3
  Bytes 1-4:  PacketID
  Bytes 5-6:  ZoneType (0=KeepIn, 1=KeepOut, 2=SearchArea)
  Byte 7:     ZoneID (auto-incrementing)
  Bytes 8+:   N pairs of (latitude, longitude) as float64

  What happens on the Jetson:
  1. _dispatch matches isinstance(command, AddZone)
  2. Logs: [CMD 3] AddZone — type: KeepOut, zone_id: 0, coords: [(33.88, -117.88), ...]
  3. Builds a JSON payload:
  {
    "zone_type": 1,
    "zone_id": 0,
    "coordinates": [[33.88, -117.88], [33.89, -117.89], ...]
  }
  4. Creates a String message with the JSON
  5. Publishes to /ngcp/add_zone ROS topic
  6. The autonomy/navigation system should subscribe to this and use the coordinates as
  geofence boundaries:
    - KeepIn → vehicle must stay inside this polygon
    - KeepOut → vehicle must not enter this polygon
    - SearchArea → vehicle should search within this polygon
  7. Calls _reply_telemetry(command) → sends telemetry back with CommandID=3

  What the GCS learns from the reply:
  - CommandID=3 confirms the zone was received
  - The GCS can track which zones have been acknowledged by matching PacketID

  ---
  Command 5 — PatientLocation

  What the GCS sends:
  Format: "=BIdd" (21 bytes)
  Byte 0:     CommandID = 5
  Bytes 1-4:  PacketID
  Bytes 5-12: Latitude (float64)
  Bytes 13-20: Longitude (float64)

  What happens on the Jetson:
  1. _dispatch matches isinstance(command, PatientLocation)
  2. Logs: [CMD 5] PatientLocation — lat: 33.882500, lon: -117.882700
  3. Creates a Point message:
    - x = latitude
    - y = longitude
    - z = 0.0
  4. Publishes to /ngcp/patient_location ROS topic
  5. The autonomy system should subscribe to this and navigate the UGV to that GPS
  coordinate to reach the patient
  6. Calls _reply_telemetry(command) with special flags:
    - message_flag=2 (indicates "patient" message)
    - message_lat=lat (echoes the patient coordinates)
    - message_lon=lon
  7. The telemetry reply is built with MessageFlag=2 and the patient's coordinates in
  MessageLat/MessageLon

  What the GCS learns from the reply:
  - CommandID=5 confirms the patient location was received
  - MessageFlag=2 specifically confirms this was a patient-related response
  - MessageLat/MessageLon echo the coordinates back so the GCS can verify the right
  location was received
  - The sensor data shows where the vehicle currently is, so the GCS can track it
  navigating toward the patient

  ---
  Current gaps

  One thing to note: the ROS topics being published (/ngcp/estop, /ngcp/add_zone,
  /ngcp/patient_location) don't currently have subscribers in your other nodes. For
  example, ugv_control_sub doesn't listen to /ngcp/estop yet. The XBee comms pipeline works
   end-to-end, but the downstream actions aren't wired up yet.
