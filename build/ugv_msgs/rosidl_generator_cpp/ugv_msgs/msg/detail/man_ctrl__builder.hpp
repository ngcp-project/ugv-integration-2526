// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ugv_msgs:msg/ManCtrl.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__MAN_CTRL__BUILDER_HPP_
#define UGV_MSGS__MSG__DETAIL__MAN_CTRL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ugv_msgs/msg/detail/man_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ugv_msgs
{

namespace msg
{

namespace builder
{

class Init_ManCtrl_arm_cmd
{
public:
  explicit Init_ManCtrl_arm_cmd(::ugv_msgs::msg::ManCtrl & msg)
  : msg_(msg)
  {}
  ::ugv_msgs::msg::ManCtrl arm_cmd(::ugv_msgs::msg::ManCtrl::_arm_cmd_type arg)
  {
    msg_.arm_cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ugv_msgs::msg::ManCtrl msg_;
};

class Init_ManCtrl_steer_cmd
{
public:
  explicit Init_ManCtrl_steer_cmd(::ugv_msgs::msg::ManCtrl & msg)
  : msg_(msg)
  {}
  Init_ManCtrl_arm_cmd steer_cmd(::ugv_msgs::msg::ManCtrl::_steer_cmd_type arg)
  {
    msg_.steer_cmd = std::move(arg);
    return Init_ManCtrl_arm_cmd(msg_);
  }

private:
  ::ugv_msgs::msg::ManCtrl msg_;
};

class Init_ManCtrl_linear_vel
{
public:
  explicit Init_ManCtrl_linear_vel(::ugv_msgs::msg::ManCtrl & msg)
  : msg_(msg)
  {}
  Init_ManCtrl_steer_cmd linear_vel(::ugv_msgs::msg::ManCtrl::_linear_vel_type arg)
  {
    msg_.linear_vel = std::move(arg);
    return Init_ManCtrl_steer_cmd(msg_);
  }

private:
  ::ugv_msgs::msg::ManCtrl msg_;
};

class Init_ManCtrl_auto_en
{
public:
  Init_ManCtrl_auto_en()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManCtrl_linear_vel auto_en(::ugv_msgs::msg::ManCtrl::_auto_en_type arg)
  {
    msg_.auto_en = std::move(arg);
    return Init_ManCtrl_linear_vel(msg_);
  }

private:
  ::ugv_msgs::msg::ManCtrl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ugv_msgs::msg::ManCtrl>()
{
  return ugv_msgs::msg::builder::Init_ManCtrl_auto_en();
}

}  // namespace ugv_msgs

#endif  // UGV_MSGS__MSG__DETAIL__MAN_CTRL__BUILDER_HPP_
