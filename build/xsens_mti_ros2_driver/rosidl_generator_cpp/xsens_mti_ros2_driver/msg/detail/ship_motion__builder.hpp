// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_mti_ros2_driver:msg/ShipMotion.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__BUILDER_HPP_
#define XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xsens_mti_ros2_driver/msg/detail/ship_motion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xsens_mti_ros2_driver
{

namespace msg
{

namespace builder
{

class Init_ShipMotion_heave_period
{
public:
  explicit Init_ShipMotion_heave_period(::xsens_mti_ros2_driver::msg::ShipMotion & msg)
  : msg_(msg)
  {}
  ::xsens_mti_ros2_driver::msg::ShipMotion heave_period(::xsens_mti_ros2_driver::msg::ShipMotion::_heave_period_type arg)
  {
    msg_.heave_period = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::ShipMotion msg_;
};

class Init_ShipMotion_heave_position
{
public:
  explicit Init_ShipMotion_heave_position(::xsens_mti_ros2_driver::msg::ShipMotion & msg)
  : msg_(msg)
  {}
  Init_ShipMotion_heave_period heave_position(::xsens_mti_ros2_driver::msg::ShipMotion::_heave_position_type arg)
  {
    msg_.heave_position = std::move(arg);
    return Init_ShipMotion_heave_period(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::ShipMotion msg_;
};

class Init_ShipMotion_header
{
public:
  Init_ShipMotion_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ShipMotion_heave_position header(::xsens_mti_ros2_driver::msg::ShipMotion::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ShipMotion_heave_position(msg_);
  }

private:
  ::xsens_mti_ros2_driver::msg::ShipMotion msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_mti_ros2_driver::msg::ShipMotion>()
{
  return xsens_mti_ros2_driver::msg::builder::Init_ShipMotion_header();
}

}  // namespace xsens_mti_ros2_driver

#endif  // XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__BUILDER_HPP_
