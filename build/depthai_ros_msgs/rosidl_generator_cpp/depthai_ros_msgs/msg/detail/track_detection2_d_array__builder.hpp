// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from depthai_ros_msgs:msg/TrackDetection2DArray.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D_ARRAY__BUILDER_HPP_
#define DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "depthai_ros_msgs/msg/detail/track_detection2_d_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace depthai_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_TrackDetection2DArray_detections
{
public:
  explicit Init_TrackDetection2DArray_detections(::depthai_ros_msgs::msg::TrackDetection2DArray & msg)
  : msg_(msg)
  {}
  ::depthai_ros_msgs::msg::TrackDetection2DArray detections(::depthai_ros_msgs::msg::TrackDetection2DArray::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::depthai_ros_msgs::msg::TrackDetection2DArray msg_;
};

class Init_TrackDetection2DArray_header
{
public:
  Init_TrackDetection2DArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackDetection2DArray_detections header(::depthai_ros_msgs::msg::TrackDetection2DArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TrackDetection2DArray_detections(msg_);
  }

private:
  ::depthai_ros_msgs::msg::TrackDetection2DArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::depthai_ros_msgs::msg::TrackDetection2DArray>()
{
  return depthai_ros_msgs::msg::builder::Init_TrackDetection2DArray_header();
}

}  // namespace depthai_ros_msgs

#endif  // DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D_ARRAY__BUILDER_HPP_
