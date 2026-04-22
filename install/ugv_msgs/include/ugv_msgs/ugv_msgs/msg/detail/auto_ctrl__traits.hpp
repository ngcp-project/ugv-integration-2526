// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ugv_msgs:msg/AutoCtrl.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__AUTO_CTRL__TRAITS_HPP_
#define UGV_MSGS__MSG__DETAIL__AUTO_CTRL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ugv_msgs/msg/detail/auto_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ugv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AutoCtrl & msg,
  std::ostream & out)
{
  out << "{";
  // member: auto_en
  {
    out << "auto_en: ";
    rosidl_generator_traits::value_to_yaml(msg.auto_en, out);
    out << ", ";
  }

  // member: heading_error
  {
    out << "heading_error: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AutoCtrl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: auto_en
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "auto_en: ";
    rosidl_generator_traits::value_to_yaml(msg.auto_en, out);
    out << "\n";
  }

  // member: heading_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_error: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AutoCtrl & msg, bool use_flow_style = false)
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
  const ugv_msgs::msg::AutoCtrl & msg,
  std::ostream & out, size_t indentation = 0)
{
  ugv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ugv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ugv_msgs::msg::AutoCtrl & msg)
{
  return ugv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ugv_msgs::msg::AutoCtrl>()
{
  return "ugv_msgs::msg::AutoCtrl";
}

template<>
inline const char * name<ugv_msgs::msg::AutoCtrl>()
{
  return "ugv_msgs/msg/AutoCtrl";
}

template<>
struct has_fixed_size<ugv_msgs::msg::AutoCtrl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ugv_msgs::msg::AutoCtrl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ugv_msgs::msg::AutoCtrl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UGV_MSGS__MSG__DETAIL__AUTO_CTRL__TRAITS_HPP_
