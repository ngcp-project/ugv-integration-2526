// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xsens_mti_ros2_driver:msg/ShipMotion.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__TRAITS_HPP_
#define XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xsens_mti_ros2_driver/msg/detail/ship_motion__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace xsens_mti_ros2_driver
{

namespace msg
{

inline void to_flow_style_yaml(
  const ShipMotion & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: heave_position
  {
    out << "heave_position: ";
    rosidl_generator_traits::value_to_yaml(msg.heave_position, out);
    out << ", ";
  }

  // member: heave_period
  {
    out << "heave_period: ";
    rosidl_generator_traits::value_to_yaml(msg.heave_period, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ShipMotion & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: heave_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heave_position: ";
    rosidl_generator_traits::value_to_yaml(msg.heave_position, out);
    out << "\n";
  }

  // member: heave_period
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heave_period: ";
    rosidl_generator_traits::value_to_yaml(msg.heave_period, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ShipMotion & msg, bool use_flow_style = false)
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

}  // namespace xsens_mti_ros2_driver

namespace rosidl_generator_traits
{

[[deprecated("use xsens_mti_ros2_driver::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const xsens_mti_ros2_driver::msg::ShipMotion & msg,
  std::ostream & out, size_t indentation = 0)
{
  xsens_mti_ros2_driver::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xsens_mti_ros2_driver::msg::to_yaml() instead")]]
inline std::string to_yaml(const xsens_mti_ros2_driver::msg::ShipMotion & msg)
{
  return xsens_mti_ros2_driver::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xsens_mti_ros2_driver::msg::ShipMotion>()
{
  return "xsens_mti_ros2_driver::msg::ShipMotion";
}

template<>
inline const char * name<xsens_mti_ros2_driver::msg::ShipMotion>()
{
  return "xsens_mti_ros2_driver/msg/ShipMotion";
}

template<>
struct has_fixed_size<xsens_mti_ros2_driver::msg::ShipMotion>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<xsens_mti_ros2_driver::msg::ShipMotion>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<xsens_mti_ros2_driver::msg::ShipMotion>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__TRAITS_HPP_
