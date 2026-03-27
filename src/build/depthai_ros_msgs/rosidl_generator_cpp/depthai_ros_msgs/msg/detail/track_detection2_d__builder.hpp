// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from depthai_ros_msgs:msg/TrackDetection2D.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D__BUILDER_HPP_
#define DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "depthai_ros_msgs/msg/detail/track_detection2_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace depthai_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_TrackDetection2D_tracking_status
{
public:
  explicit Init_TrackDetection2D_tracking_status(::depthai_ros_msgs::msg::TrackDetection2D & msg)
  : msg_(msg)
  {}
  ::depthai_ros_msgs::msg::TrackDetection2D tracking_status(::depthai_ros_msgs::msg::TrackDetection2D::_tracking_status_type arg)
  {
    msg_.tracking_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::depthai_ros_msgs::msg::TrackDetection2D msg_;
};

class Init_TrackDetection2D_tracking_age
{
public:
  explicit Init_TrackDetection2D_tracking_age(::depthai_ros_msgs::msg::TrackDetection2D & msg)
  : msg_(msg)
  {}
  Init_TrackDetection2D_tracking_status tracking_age(::depthai_ros_msgs::msg::TrackDetection2D::_tracking_age_type arg)
  {
    msg_.tracking_age = std::move(arg);
    return Init_TrackDetection2D_tracking_status(msg_);
  }

private:
  ::depthai_ros_msgs::msg::TrackDetection2D msg_;
};

class Init_TrackDetection2D_tracking_id
{
public:
  explicit Init_TrackDetection2D_tracking_id(::depthai_ros_msgs::msg::TrackDetection2D & msg)
  : msg_(msg)
  {}
  Init_TrackDetection2D_tracking_age tracking_id(::depthai_ros_msgs::msg::TrackDetection2D::_tracking_id_type arg)
  {
    msg_.tracking_id = std::move(arg);
    return Init_TrackDetection2D_tracking_age(msg_);
  }

private:
  ::depthai_ros_msgs::msg::TrackDetection2D msg_;
};

class Init_TrackDetection2D_is_tracking
{
public:
  explicit Init_TrackDetection2D_is_tracking(::depthai_ros_msgs::msg::TrackDetection2D & msg)
  : msg_(msg)
  {}
  Init_TrackDetection2D_tracking_id is_tracking(::depthai_ros_msgs::msg::TrackDetection2D::_is_tracking_type arg)
  {
    msg_.is_tracking = std::move(arg);
    return Init_TrackDetection2D_tracking_id(msg_);
  }

private:
  ::depthai_ros_msgs::msg::TrackDetection2D msg_;
};

class Init_TrackDetection2D_bbox
{
public:
  explicit Init_TrackDetection2D_bbox(::depthai_ros_msgs::msg::TrackDetection2D & msg)
  : msg_(msg)
  {}
  Init_TrackDetection2D_is_tracking bbox(::depthai_ros_msgs::msg::TrackDetection2D::_bbox_type arg)
  {
    msg_.bbox = std::move(arg);
    return Init_TrackDetection2D_is_tracking(msg_);
  }

private:
  ::depthai_ros_msgs::msg::TrackDetection2D msg_;
};

class Init_TrackDetection2D_results
{
public:
  Init_TrackDetection2D_results()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackDetection2D_bbox results(::depthai_ros_msgs::msg::TrackDetection2D::_results_type arg)
  {
    msg_.results = std::move(arg);
    return Init_TrackDetection2D_bbox(msg_);
  }

private:
  ::depthai_ros_msgs::msg::TrackDetection2D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::depthai_ros_msgs::msg::TrackDetection2D>()
{
  return depthai_ros_msgs::msg::builder::Init_TrackDetection2D_results();
}

}  // namespace depthai_ros_msgs

#endif  // DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D__BUILDER_HPP_
