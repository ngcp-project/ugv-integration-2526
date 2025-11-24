// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__TRAITS_HPP_
#define XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace xsens_mti_ros2_driver
{

namespace msg
{

inline void to_flow_style_yaml(
  const XsStatusWord & msg,
  std::ostream & out)
{
  out << "{";
  // member: selftest
  {
    out << "selftest: ";
    rosidl_generator_traits::value_to_yaml(msg.selftest, out);
    out << ", ";
  }

  // member: filter_valid
  {
    out << "filter_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.filter_valid, out);
    out << ", ";
  }

  // member: gnss_fix
  {
    out << "gnss_fix: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_fix, out);
    out << ", ";
  }

  // member: no_rotation_update_status
  {
    out << "no_rotation_update_status: ";
    rosidl_generator_traits::value_to_yaml(msg.no_rotation_update_status, out);
    out << ", ";
  }

  // member: representative_motion
  {
    out << "representative_motion: ";
    rosidl_generator_traits::value_to_yaml(msg.representative_motion, out);
    out << ", ";
  }

  // member: clock_bias_estimation
  {
    out << "clock_bias_estimation: ";
    rosidl_generator_traits::value_to_yaml(msg.clock_bias_estimation, out);
    out << ", ";
  }

  // member: clipflag_acc_x
  {
    out << "clipflag_acc_x: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_acc_x, out);
    out << ", ";
  }

  // member: clipflag_acc_y
  {
    out << "clipflag_acc_y: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_acc_y, out);
    out << ", ";
  }

  // member: clipflag_acc_z
  {
    out << "clipflag_acc_z: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_acc_z, out);
    out << ", ";
  }

  // member: clipflag_gyr_x
  {
    out << "clipflag_gyr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_gyr_x, out);
    out << ", ";
  }

  // member: clipflag_gyr_y
  {
    out << "clipflag_gyr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_gyr_y, out);
    out << ", ";
  }

  // member: clipflag_gyr_z
  {
    out << "clipflag_gyr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_gyr_z, out);
    out << ", ";
  }

  // member: clipflag_mag_x
  {
    out << "clipflag_mag_x: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_mag_x, out);
    out << ", ";
  }

  // member: clipflag_mag_y
  {
    out << "clipflag_mag_y: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_mag_y, out);
    out << ", ";
  }

  // member: clipflag_mag_z
  {
    out << "clipflag_mag_z: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_mag_z, out);
    out << ", ";
  }

  // member: clipping_indication
  {
    out << "clipping_indication: ";
    rosidl_generator_traits::value_to_yaml(msg.clipping_indication, out);
    out << ", ";
  }

  // member: syncin_marker
  {
    out << "syncin_marker: ";
    rosidl_generator_traits::value_to_yaml(msg.syncin_marker, out);
    out << ", ";
  }

  // member: syncout_marker
  {
    out << "syncout_marker: ";
    rosidl_generator_traits::value_to_yaml(msg.syncout_marker, out);
    out << ", ";
  }

  // member: filter_mode
  {
    out << "filter_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.filter_mode, out);
    out << ", ";
  }

  // member: have_gnss_time_pulse
  {
    out << "have_gnss_time_pulse: ";
    rosidl_generator_traits::value_to_yaml(msg.have_gnss_time_pulse, out);
    out << ", ";
  }

  // member: rtk_status
  {
    out << "rtk_status: ";
    rosidl_generator_traits::value_to_yaml(msg.rtk_status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const XsStatusWord & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: selftest
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "selftest: ";
    rosidl_generator_traits::value_to_yaml(msg.selftest, out);
    out << "\n";
  }

  // member: filter_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filter_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.filter_valid, out);
    out << "\n";
  }

  // member: gnss_fix
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_fix: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_fix, out);
    out << "\n";
  }

  // member: no_rotation_update_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "no_rotation_update_status: ";
    rosidl_generator_traits::value_to_yaml(msg.no_rotation_update_status, out);
    out << "\n";
  }

  // member: representative_motion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "representative_motion: ";
    rosidl_generator_traits::value_to_yaml(msg.representative_motion, out);
    out << "\n";
  }

  // member: clock_bias_estimation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clock_bias_estimation: ";
    rosidl_generator_traits::value_to_yaml(msg.clock_bias_estimation, out);
    out << "\n";
  }

  // member: clipflag_acc_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipflag_acc_x: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_acc_x, out);
    out << "\n";
  }

  // member: clipflag_acc_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipflag_acc_y: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_acc_y, out);
    out << "\n";
  }

  // member: clipflag_acc_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipflag_acc_z: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_acc_z, out);
    out << "\n";
  }

  // member: clipflag_gyr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipflag_gyr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_gyr_x, out);
    out << "\n";
  }

  // member: clipflag_gyr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipflag_gyr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_gyr_y, out);
    out << "\n";
  }

  // member: clipflag_gyr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipflag_gyr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_gyr_z, out);
    out << "\n";
  }

  // member: clipflag_mag_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipflag_mag_x: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_mag_x, out);
    out << "\n";
  }

  // member: clipflag_mag_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipflag_mag_y: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_mag_y, out);
    out << "\n";
  }

  // member: clipflag_mag_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipflag_mag_z: ";
    rosidl_generator_traits::value_to_yaml(msg.clipflag_mag_z, out);
    out << "\n";
  }

  // member: clipping_indication
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipping_indication: ";
    rosidl_generator_traits::value_to_yaml(msg.clipping_indication, out);
    out << "\n";
  }

  // member: syncin_marker
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "syncin_marker: ";
    rosidl_generator_traits::value_to_yaml(msg.syncin_marker, out);
    out << "\n";
  }

  // member: syncout_marker
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "syncout_marker: ";
    rosidl_generator_traits::value_to_yaml(msg.syncout_marker, out);
    out << "\n";
  }

  // member: filter_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filter_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.filter_mode, out);
    out << "\n";
  }

  // member: have_gnss_time_pulse
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "have_gnss_time_pulse: ";
    rosidl_generator_traits::value_to_yaml(msg.have_gnss_time_pulse, out);
    out << "\n";
  }

  // member: rtk_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rtk_status: ";
    rosidl_generator_traits::value_to_yaml(msg.rtk_status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const XsStatusWord & msg, bool use_flow_style = false)
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
  const xsens_mti_ros2_driver::msg::XsStatusWord & msg,
  std::ostream & out, size_t indentation = 0)
{
  xsens_mti_ros2_driver::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xsens_mti_ros2_driver::msg::to_yaml() instead")]]
inline std::string to_yaml(const xsens_mti_ros2_driver::msg::XsStatusWord & msg)
{
  return xsens_mti_ros2_driver::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xsens_mti_ros2_driver::msg::XsStatusWord>()
{
  return "xsens_mti_ros2_driver::msg::XsStatusWord";
}

template<>
inline const char * name<xsens_mti_ros2_driver::msg::XsStatusWord>()
{
  return "xsens_mti_ros2_driver/msg/XsStatusWord";
}

template<>
struct has_fixed_size<xsens_mti_ros2_driver::msg::XsStatusWord>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xsens_mti_ros2_driver::msg::XsStatusWord>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xsens_mti_ros2_driver::msg::XsStatusWord>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__TRAITS_HPP_
