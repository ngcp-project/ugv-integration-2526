// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__BUILDER_HPP_
#define XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xsens_mti_ros2_driver
{

namespace msg
{

namespace builder
{

class Init_XsStatusWord_rtk_status
{
public:
  explicit Init_XsStatusWord_rtk_status(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  ::xsens_mti_ros2_driver::msg::XsStatusWord rtk_status(::xsens_mti_ros2_driver::msg::XsStatusWord::_rtk_status_type arg)
  {
    msg_.rtk_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_have_gnss_time_pulse
{
public:
  explicit Init_XsStatusWord_have_gnss_time_pulse(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_rtk_status have_gnss_time_pulse(::xsens_mti_ros2_driver::msg::XsStatusWord::_have_gnss_time_pulse_type arg)
  {
    msg_.have_gnss_time_pulse = std::move(arg);
    return Init_XsStatusWord_rtk_status(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_filter_mode
{
public:
  explicit Init_XsStatusWord_filter_mode(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_have_gnss_time_pulse filter_mode(::xsens_mti_ros2_driver::msg::XsStatusWord::_filter_mode_type arg)
  {
    msg_.filter_mode = std::move(arg);
    return Init_XsStatusWord_have_gnss_time_pulse(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_syncout_marker
{
public:
  explicit Init_XsStatusWord_syncout_marker(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_filter_mode syncout_marker(::xsens_mti_ros2_driver::msg::XsStatusWord::_syncout_marker_type arg)
  {
    msg_.syncout_marker = std::move(arg);
    return Init_XsStatusWord_filter_mode(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_syncin_marker
{
public:
  explicit Init_XsStatusWord_syncin_marker(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_syncout_marker syncin_marker(::xsens_mti_ros2_driver::msg::XsStatusWord::_syncin_marker_type arg)
  {
    msg_.syncin_marker = std::move(arg);
    return Init_XsStatusWord_syncout_marker(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clipping_indication
{
public:
  explicit Init_XsStatusWord_clipping_indication(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_syncin_marker clipping_indication(::xsens_mti_ros2_driver::msg::XsStatusWord::_clipping_indication_type arg)
  {
    msg_.clipping_indication = std::move(arg);
    return Init_XsStatusWord_syncin_marker(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clipflag_mag_z
{
public:
  explicit Init_XsStatusWord_clipflag_mag_z(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clipping_indication clipflag_mag_z(::xsens_mti_ros2_driver::msg::XsStatusWord::_clipflag_mag_z_type arg)
  {
    msg_.clipflag_mag_z = std::move(arg);
    return Init_XsStatusWord_clipping_indication(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clipflag_mag_y
{
public:
  explicit Init_XsStatusWord_clipflag_mag_y(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clipflag_mag_z clipflag_mag_y(::xsens_mti_ros2_driver::msg::XsStatusWord::_clipflag_mag_y_type arg)
  {
    msg_.clipflag_mag_y = std::move(arg);
    return Init_XsStatusWord_clipflag_mag_z(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clipflag_mag_x
{
public:
  explicit Init_XsStatusWord_clipflag_mag_x(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clipflag_mag_y clipflag_mag_x(::xsens_mti_ros2_driver::msg::XsStatusWord::_clipflag_mag_x_type arg)
  {
    msg_.clipflag_mag_x = std::move(arg);
    return Init_XsStatusWord_clipflag_mag_y(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clipflag_gyr_z
{
public:
  explicit Init_XsStatusWord_clipflag_gyr_z(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clipflag_mag_x clipflag_gyr_z(::xsens_mti_ros2_driver::msg::XsStatusWord::_clipflag_gyr_z_type arg)
  {
    msg_.clipflag_gyr_z = std::move(arg);
    return Init_XsStatusWord_clipflag_mag_x(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clipflag_gyr_y
{
public:
  explicit Init_XsStatusWord_clipflag_gyr_y(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clipflag_gyr_z clipflag_gyr_y(::xsens_mti_ros2_driver::msg::XsStatusWord::_clipflag_gyr_y_type arg)
  {
    msg_.clipflag_gyr_y = std::move(arg);
    return Init_XsStatusWord_clipflag_gyr_z(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clipflag_gyr_x
{
public:
  explicit Init_XsStatusWord_clipflag_gyr_x(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clipflag_gyr_y clipflag_gyr_x(::xsens_mti_ros2_driver::msg::XsStatusWord::_clipflag_gyr_x_type arg)
  {
    msg_.clipflag_gyr_x = std::move(arg);
    return Init_XsStatusWord_clipflag_gyr_y(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clipflag_acc_z
{
public:
  explicit Init_XsStatusWord_clipflag_acc_z(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clipflag_gyr_x clipflag_acc_z(::xsens_mti_ros2_driver::msg::XsStatusWord::_clipflag_acc_z_type arg)
  {
    msg_.clipflag_acc_z = std::move(arg);
    return Init_XsStatusWord_clipflag_gyr_x(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clipflag_acc_y
{
public:
  explicit Init_XsStatusWord_clipflag_acc_y(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clipflag_acc_z clipflag_acc_y(::xsens_mti_ros2_driver::msg::XsStatusWord::_clipflag_acc_y_type arg)
  {
    msg_.clipflag_acc_y = std::move(arg);
    return Init_XsStatusWord_clipflag_acc_z(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clipflag_acc_x
{
public:
  explicit Init_XsStatusWord_clipflag_acc_x(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clipflag_acc_y clipflag_acc_x(::xsens_mti_ros2_driver::msg::XsStatusWord::_clipflag_acc_x_type arg)
  {
    msg_.clipflag_acc_x = std::move(arg);
    return Init_XsStatusWord_clipflag_acc_y(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_clock_bias_estimation
{
public:
  explicit Init_XsStatusWord_clock_bias_estimation(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clipflag_acc_x clock_bias_estimation(::xsens_mti_ros2_driver::msg::XsStatusWord::_clock_bias_estimation_type arg)
  {
    msg_.clock_bias_estimation = std::move(arg);
    return Init_XsStatusWord_clipflag_acc_x(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_representative_motion
{
public:
  explicit Init_XsStatusWord_representative_motion(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_clock_bias_estimation representative_motion(::xsens_mti_ros2_driver::msg::XsStatusWord::_representative_motion_type arg)
  {
    msg_.representative_motion = std::move(arg);
    return Init_XsStatusWord_clock_bias_estimation(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_no_rotation_update_status
{
public:
  explicit Init_XsStatusWord_no_rotation_update_status(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_representative_motion no_rotation_update_status(::xsens_mti_ros2_driver::msg::XsStatusWord::_no_rotation_update_status_type arg)
  {
    msg_.no_rotation_update_status = std::move(arg);
    return Init_XsStatusWord_representative_motion(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_gnss_fix
{
public:
  explicit Init_XsStatusWord_gnss_fix(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_no_rotation_update_status gnss_fix(::xsens_mti_ros2_driver::msg::XsStatusWord::_gnss_fix_type arg)
  {
    msg_.gnss_fix = std::move(arg);
    return Init_XsStatusWord_no_rotation_update_status(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_filter_valid
{
public:
  explicit Init_XsStatusWord_filter_valid(::xsens_mti_ros2_driver::msg::XsStatusWord & msg)
  : msg_(msg)
  {}
  Init_XsStatusWord_gnss_fix filter_valid(::xsens_mti_ros2_driver::msg::XsStatusWord::_filter_valid_type arg)
  {
    msg_.filter_valid = std::move(arg);
    return Init_XsStatusWord_gnss_fix(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

class Init_XsStatusWord_selftest
{
public:
  Init_XsStatusWord_selftest()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_XsStatusWord_filter_valid selftest(::xsens_mti_ros2_driver::msg::XsStatusWord::_selftest_type arg)
  {
    msg_.selftest = std::move(arg);
    return Init_XsStatusWord_filter_valid(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::XsStatusWord msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_mti_ros2_driver::msg::XsStatusWord>()
{
  return xsens_mti_ros2_driver::msg::builder::Init_XsStatusWord_selftest();
}

}  // namespace xsens_mti_ros2_driver

#endif  // XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__BUILDER_HPP_
