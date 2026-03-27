// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ugv_msgs:msg/UGVTelemetry.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__TRAITS_HPP_
#define UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ugv_msgs/msg/detail/ugv_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ugv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const UGVTelemetry & msg,
  std::ostream & out)
{
  out << "{";
  // member: speed_fps
  {
    out << "speed_fps: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_fps, out);
    out << ", ";
  }

  // member: pitch_deg
  {
    out << "pitch_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_deg, out);
    out << ", ";
  }

  // member: yaw_deg
  {
    out << "yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_deg, out);
    out << ", ";
  }

  // member: roll_deg
  {
    out << "roll_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_deg, out);
    out << ", ";
  }

  // member: altitude_ft
  {
    out << "altitude_ft: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_ft, out);
    out << ", ";
  }

  // member: latitude
  {
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << ", ";
  }

  // member: longitude
  {
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UGVTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: speed_fps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_fps: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_fps, out);
    out << "\n";
  }

  // member: pitch_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_deg, out);
    out << "\n";
  }

  // member: yaw_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_deg, out);
    out << "\n";
  }

  // member: roll_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_deg, out);
    out << "\n";
  }

  // member: altitude_ft
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude_ft: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_ft, out);
    out << "\n";
  }

  // member: latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << "\n";
  }

  // member: longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UGVTelemetry & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ugv_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ugv_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ugv_msgs::msg::UGVTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  ugv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ugv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ugv_msgs::msg::UGVTelemetry & msg)
{
  return ugv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ugv_msgs::msg::UGVTelemetry>()
{
  return "ugv_msgs::msg::UGVTelemetry";
}

template<>
inline const char * name<ugv_msgs::msg::UGVTelemetry>()
{
  return "ugv_msgs/msg/UGVTelemetry";
}

template<>
struct has_fixed_size<ugv_msgs::msg::UGVTelemetry>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ugv_msgs::msg::UGVTelemetry>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ugv_msgs::msg::UGVTelemetry>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__TRAITS_HPP_
