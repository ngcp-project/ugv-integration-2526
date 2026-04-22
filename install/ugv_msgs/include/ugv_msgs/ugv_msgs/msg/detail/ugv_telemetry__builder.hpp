// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ugv_msgs:msg/UGVTelemetry.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__BUILDER_HPP_
#define UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ugv_msgs/msg/detail/ugv_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ugv_msgs
{

namespace msg
{

namespace builder
{

class Init_UGVTelemetry_longitude
{
public:
  explicit Init_UGVTelemetry_longitude(::ugv_msgs::msg::UGVTelemetry & msg)
  : msg_(msg)
  {}
  ::ugv_msgs::msg::UGVTelemetry longitude(::ugv_msgs::msg::UGVTelemetry::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ugv_msgs::msg::UGVTelemetry msg_;
};

class Init_UGVTelemetry_latitude
{
public:
  explicit Init_UGVTelemetry_latitude(::ugv_msgs::msg::UGVTelemetry & msg)
  : msg_(msg)
  {}
  Init_UGVTelemetry_longitude latitude(::ugv_msgs::msg::UGVTelemetry::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_UGVTelemetry_longitude(msg_);
  }

private:
  ::ugv_msgs::msg::UGVTelemetry msg_;
};

class Init_UGVTelemetry_altitude_ft
{
public:
  explicit Init_UGVTelemetry_altitude_ft(::ugv_msgs::msg::UGVTelemetry & msg)
  : msg_(msg)
  {}
  Init_UGVTelemetry_latitude altitude_ft(::ugv_msgs::msg::UGVTelemetry::_altitude_ft_type arg)
  {
    msg_.altitude_ft = std::move(arg);
    return Init_UGVTelemetry_latitude(msg_);
  }

private:
  ::ugv_msgs::msg::UGVTelemetry msg_;
};

class Init_UGVTelemetry_roll_deg
{
public:
  explicit Init_UGVTelemetry_roll_deg(::ugv_msgs::msg::UGVTelemetry & msg)
  : msg_(msg)
  {}
  Init_UGVTelemetry_altitude_ft roll_deg(::ugv_msgs::msg::UGVTelemetry::_roll_deg_type arg)
  {
    msg_.roll_deg = std::move(arg);
    return Init_UGVTelemetry_altitude_ft(msg_);
  }

private:
  ::ugv_msgs::msg::UGVTelemetry msg_;
};

class Init_UGVTelemetry_yaw_deg
{
public:
  explicit Init_UGVTelemetry_yaw_deg(::ugv_msgs::msg::UGVTelemetry & msg)
  : msg_(msg)
  {}
  Init_UGVTelemetry_roll_deg yaw_deg(::ugv_msgs::msg::UGVTelemetry::_yaw_deg_type arg)
  {
    msg_.yaw_deg = std::move(arg);
    return Init_UGVTelemetry_roll_deg(msg_);
  }

private:
  ::ugv_msgs::msg::UGVTelemetry msg_;
};

class Init_UGVTelemetry_pitch_deg
{
public:
  explicit Init_UGVTelemetry_pitch_deg(::ugv_msgs::msg::UGVTelemetry & msg)
  : msg_(msg)
  {}
  Init_UGVTelemetry_yaw_deg pitch_deg(::ugv_msgs::msg::UGVTelemetry::_pitch_deg_type arg)
  {
    msg_.pitch_deg = std::move(arg);
    return Init_UGVTelemetry_yaw_deg(msg_);
  }

private:
  ::ugv_msgs::msg::UGVTelemetry msg_;
};

class Init_UGVTelemetry_speed_fps
{
public:
  Init_UGVTelemetry_speed_fps()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UGVTelemetry_pitch_deg speed_fps(::ugv_msgs::msg::UGVTelemetry::_speed_fps_type arg)
  {
    msg_.speed_fps = std::move(arg);
    return Init_UGVTelemetry_pitch_deg(msg_);
  }

private:
  ::ugv_msgs::msg::UGVTelemetry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ugv_msgs::msg::UGVTelemetry>()
{
  return ugv_msgs::msg::builder::Init_UGVTelemetry_speed_fps();
}

}  // namespace ugv_msgs

#endif  // UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__BUILDER_HPP_
