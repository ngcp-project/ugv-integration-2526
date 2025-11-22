// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ugv_msgs:msg/AutoCtrl.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__AUTO_CTRL__BUILDER_HPP_
#define UGV_MSGS__MSG__DETAIL__AUTO_CTRL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ugv_msgs/msg/detail/auto_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ugv_msgs
{

namespace msg
{

namespace builder
{

class Init_AutoCtrl_heading_error
{
public:
  explicit Init_AutoCtrl_heading_error(::ugv_msgs::msg::AutoCtrl & msg)
  : msg_(msg)
  {}
  ::ugv_msgs::msg::AutoCtrl heading_error(::ugv_msgs::msg::AutoCtrl::_heading_error_type arg)
  {
    msg_.heading_error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ugv_msgs::msg::AutoCtrl msg_;
};

class Init_AutoCtrl_auto_en
{
public:
  Init_AutoCtrl_auto_en()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AutoCtrl_heading_error auto_en(::ugv_msgs::msg::AutoCtrl::_auto_en_type arg)
  {
    msg_.auto_en = std::move(arg);
    return Init_AutoCtrl_heading_error(msg_);
  }

private:
  ::ugv_msgs::msg::AutoCtrl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ugv_msgs::msg::AutoCtrl>()
{
  return ugv_msgs::msg::builder::Init_AutoCtrl_auto_en();
}

}  // namespace ugv_msgs

#endif  // UGV_MSGS__MSG__DETAIL__AUTO_CTRL__BUILDER_HPP_
