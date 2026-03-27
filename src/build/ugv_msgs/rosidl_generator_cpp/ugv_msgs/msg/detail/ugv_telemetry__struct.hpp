// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ugv_msgs:msg/UGVTelemetry.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__STRUCT_HPP_
#define UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ugv_msgs__msg__UGVTelemetry __attribute__((deprecated))
#else
# define DEPRECATED__ugv_msgs__msg__UGVTelemetry __declspec(deprecated)
#endif

namespace ugv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UGVTelemetry_
{
  using Type = UGVTelemetry_<ContainerAllocator>;

  explicit UGVTelemetry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed_fps = 0.0f;
      this->pitch_deg = 0.0f;
      this->yaw_deg = 0.0f;
      this->roll_deg = 0.0f;
      this->altitude_ft = 0.0f;
      this->latitude = 0.0;
      this->longitude = 0.0;
    }
  }

  explicit UGVTelemetry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed_fps = 0.0f;
      this->pitch_deg = 0.0f;
      this->yaw_deg = 0.0f;
      this->roll_deg = 0.0f;
      this->altitude_ft = 0.0f;
      this->latitude = 0.0;
      this->longitude = 0.0;
    }
  }

  // field types and members
  using _speed_fps_type =
    float;
  _speed_fps_type speed_fps;
  using _pitch_deg_type =
    float;
  _pitch_deg_type pitch_deg;
  using _yaw_deg_type =
    float;
  _yaw_deg_type yaw_deg;
  using _roll_deg_type =
    float;
  _roll_deg_type roll_deg;
  using _altitude_ft_type =
    float;
  _altitude_ft_type altitude_ft;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _longitude_type =
    double;
  _longitude_type longitude;

  // setters for named parameter idiom
  Type & set__speed_fps(
    const float & _arg)
  {
    this->speed_fps = _arg;
    return *this;
  }
  Type & set__pitch_deg(
    const float & _arg)
  {
    this->pitch_deg = _arg;
    return *this;
  }
  Type & set__yaw_deg(
    const float & _arg)
  {
    this->yaw_deg = _arg;
    return *this;
  }
  Type & set__roll_deg(
    const float & _arg)
  {
    this->roll_deg = _arg;
    return *this;
  }
  Type & set__altitude_ft(
    const float & _arg)
  {
    this->altitude_ft = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ugv_msgs::msg::UGVTelemetry_<ContainerAllocator> *;
  using ConstRawPtr =
    const ugv_msgs::msg::UGVTelemetry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ugv_msgs::msg::UGVTelemetry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ugv_msgs::msg::UGVTelemetry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ugv_msgs::msg::UGVTelemetry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ugv_msgs::msg::UGVTelemetry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ugv_msgs::msg::UGVTelemetry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ugv_msgs::msg::UGVTelemetry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ugv_msgs::msg::UGVTelemetry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ugv_msgs::msg::UGVTelemetry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ugv_msgs__msg__UGVTelemetry
    std::shared_ptr<ugv_msgs::msg::UGVTelemetry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ugv_msgs__msg__UGVTelemetry
    std::shared_ptr<ugv_msgs::msg::UGVTelemetry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UGVTelemetry_ & other) const
  {
    if (this->speed_fps != other.speed_fps) {
      return false;
    }
    if (this->pitch_deg != other.pitch_deg) {
      return false;
    }
    if (this->yaw_deg != other.yaw_deg) {
      return false;
    }
    if (this->roll_deg != other.roll_deg) {
      return false;
    }
    if (this->altitude_ft != other.altitude_ft) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    return true;
  }
  bool operator!=(const UGVTelemetry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UGVTelemetry_

// alias to use template instance with default allocator
using UGVTelemetry =
  ugv_msgs::msg::UGVTelemetry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ugv_msgs

#endif  // UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__STRUCT_HPP_
