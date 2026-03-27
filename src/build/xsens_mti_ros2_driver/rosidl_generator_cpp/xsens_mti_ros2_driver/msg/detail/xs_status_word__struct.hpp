// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__STRUCT_HPP_
#define XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__xsens_mti_ros2_driver__msg__XsStatusWord __attribute__((deprecated))
#else
# define DEPRECATED__xsens_mti_ros2_driver__msg__XsStatusWord __declspec(deprecated)
#endif

namespace xsens_mti_ros2_driver
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct XsStatusWord_
{
  using Type = XsStatusWord_<ContainerAllocator>;

  explicit XsStatusWord_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->selftest = false;
      this->filter_valid = false;
      this->gnss_fix = false;
      this->no_rotation_update_status = 0;
      this->representative_motion = false;
      this->clock_bias_estimation = false;
      this->clipflag_acc_x = false;
      this->clipflag_acc_y = false;
      this->clipflag_acc_z = false;
      this->clipflag_gyr_x = false;
      this->clipflag_gyr_y = false;
      this->clipflag_gyr_z = false;
      this->clipflag_mag_x = false;
      this->clipflag_mag_y = false;
      this->clipflag_mag_z = false;
      this->clipping_indication = false;
      this->syncin_marker = false;
      this->syncout_marker = false;
      this->filter_mode = 0;
      this->have_gnss_time_pulse = false;
      this->rtk_status = 0;
    }
  }

  explicit XsStatusWord_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->selftest = false;
      this->filter_valid = false;
      this->gnss_fix = false;
      this->no_rotation_update_status = 0;
      this->representative_motion = false;
      this->clock_bias_estimation = false;
      this->clipflag_acc_x = false;
      this->clipflag_acc_y = false;
      this->clipflag_acc_z = false;
      this->clipflag_gyr_x = false;
      this->clipflag_gyr_y = false;
      this->clipflag_gyr_z = false;
      this->clipflag_mag_x = false;
      this->clipflag_mag_y = false;
      this->clipflag_mag_z = false;
      this->clipping_indication = false;
      this->syncin_marker = false;
      this->syncout_marker = false;
      this->filter_mode = 0;
      this->have_gnss_time_pulse = false;
      this->rtk_status = 0;
    }
  }

  // field types and members
  using _selftest_type =
    bool;
  _selftest_type selftest;
  using _filter_valid_type =
    bool;
  _filter_valid_type filter_valid;
  using _gnss_fix_type =
    bool;
  _gnss_fix_type gnss_fix;
  using _no_rotation_update_status_type =
    uint8_t;
  _no_rotation_update_status_type no_rotation_update_status;
  using _representative_motion_type =
    bool;
  _representative_motion_type representative_motion;
  using _clock_bias_estimation_type =
    bool;
  _clock_bias_estimation_type clock_bias_estimation;
  using _clipflag_acc_x_type =
    bool;
  _clipflag_acc_x_type clipflag_acc_x;
  using _clipflag_acc_y_type =
    bool;
  _clipflag_acc_y_type clipflag_acc_y;
  using _clipflag_acc_z_type =
    bool;
  _clipflag_acc_z_type clipflag_acc_z;
  using _clipflag_gyr_x_type =
    bool;
  _clipflag_gyr_x_type clipflag_gyr_x;
  using _clipflag_gyr_y_type =
    bool;
  _clipflag_gyr_y_type clipflag_gyr_y;
  using _clipflag_gyr_z_type =
    bool;
  _clipflag_gyr_z_type clipflag_gyr_z;
  using _clipflag_mag_x_type =
    bool;
  _clipflag_mag_x_type clipflag_mag_x;
  using _clipflag_mag_y_type =
    bool;
  _clipflag_mag_y_type clipflag_mag_y;
  using _clipflag_mag_z_type =
    bool;
  _clipflag_mag_z_type clipflag_mag_z;
  using _clipping_indication_type =
    bool;
  _clipping_indication_type clipping_indication;
  using _syncin_marker_type =
    bool;
  _syncin_marker_type syncin_marker;
  using _syncout_marker_type =
    bool;
  _syncout_marker_type syncout_marker;
  using _filter_mode_type =
    uint8_t;
  _filter_mode_type filter_mode;
  using _have_gnss_time_pulse_type =
    bool;
  _have_gnss_time_pulse_type have_gnss_time_pulse;
  using _rtk_status_type =
    uint8_t;
  _rtk_status_type rtk_status;

  // setters for named parameter idiom
  Type & set__selftest(
    const bool & _arg)
  {
    this->selftest = _arg;
    return *this;
  }
  Type & set__filter_valid(
    const bool & _arg)
  {
    this->filter_valid = _arg;
    return *this;
  }
  Type & set__gnss_fix(
    const bool & _arg)
  {
    this->gnss_fix = _arg;
    return *this;
  }
  Type & set__no_rotation_update_status(
    const uint8_t & _arg)
  {
    this->no_rotation_update_status = _arg;
    return *this;
  }
  Type & set__representative_motion(
    const bool & _arg)
  {
    this->representative_motion = _arg;
    return *this;
  }
  Type & set__clock_bias_estimation(
    const bool & _arg)
  {
    this->clock_bias_estimation = _arg;
    return *this;
  }
  Type & set__clipflag_acc_x(
    const bool & _arg)
  {
    this->clipflag_acc_x = _arg;
    return *this;
  }
  Type & set__clipflag_acc_y(
    const bool & _arg)
  {
    this->clipflag_acc_y = _arg;
    return *this;
  }
  Type & set__clipflag_acc_z(
    const bool & _arg)
  {
    this->clipflag_acc_z = _arg;
    return *this;
  }
  Type & set__clipflag_gyr_x(
    const bool & _arg)
  {
    this->clipflag_gyr_x = _arg;
    return *this;
  }
  Type & set__clipflag_gyr_y(
    const bool & _arg)
  {
    this->clipflag_gyr_y = _arg;
    return *this;
  }
  Type & set__clipflag_gyr_z(
    const bool & _arg)
  {
    this->clipflag_gyr_z = _arg;
    return *this;
  }
  Type & set__clipflag_mag_x(
    const bool & _arg)
  {
    this->clipflag_mag_x = _arg;
    return *this;
  }
  Type & set__clipflag_mag_y(
    const bool & _arg)
  {
    this->clipflag_mag_y = _arg;
    return *this;
  }
  Type & set__clipflag_mag_z(
    const bool & _arg)
  {
    this->clipflag_mag_z = _arg;
    return *this;
  }
  Type & set__clipping_indication(
    const bool & _arg)
  {
    this->clipping_indication = _arg;
    return *this;
  }
  Type & set__syncin_marker(
    const bool & _arg)
  {
    this->syncin_marker = _arg;
    return *this;
  }
  Type & set__syncout_marker(
    const bool & _arg)
  {
    this->syncout_marker = _arg;
    return *this;
  }
  Type & set__filter_mode(
    const uint8_t & _arg)
  {
    this->filter_mode = _arg;
    return *this;
  }
  Type & set__have_gnss_time_pulse(
    const bool & _arg)
  {
    this->have_gnss_time_pulse = _arg;
    return *this;
  }
  Type & set__rtk_status(
    const uint8_t & _arg)
  {
    this->rtk_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_mti_ros2_driver__msg__XsStatusWord
    std::shared_ptr<xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_mti_ros2_driver__msg__XsStatusWord
    std::shared_ptr<xsens_mti_ros2_driver::msg::XsStatusWord_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const XsStatusWord_ & other) const
  {
    if (this->selftest != other.selftest) {
      return false;
    }
    if (this->filter_valid != other.filter_valid) {
      return false;
    }
    if (this->gnss_fix != other.gnss_fix) {
      return false;
    }
    if (this->no_rotation_update_status != other.no_rotation_update_status) {
      return false;
    }
    if (this->representative_motion != other.representative_motion) {
      return false;
    }
    if (this->clock_bias_estimation != other.clock_bias_estimation) {
      return false;
    }
    if (this->clipflag_acc_x != other.clipflag_acc_x) {
      return false;
    }
    if (this->clipflag_acc_y != other.clipflag_acc_y) {
      return false;
    }
    if (this->clipflag_acc_z != other.clipflag_acc_z) {
      return false;
    }
    if (this->clipflag_gyr_x != other.clipflag_gyr_x) {
      return false;
    }
    if (this->clipflag_gyr_y != other.clipflag_gyr_y) {
      return false;
    }
    if (this->clipflag_gyr_z != other.clipflag_gyr_z) {
      return false;
    }
    if (this->clipflag_mag_x != other.clipflag_mag_x) {
      return false;
    }
    if (this->clipflag_mag_y != other.clipflag_mag_y) {
      return false;
    }
    if (this->clipflag_mag_z != other.clipflag_mag_z) {
      return false;
    }
    if (this->clipping_indication != other.clipping_indication) {
      return false;
    }
    if (this->syncin_marker != other.syncin_marker) {
      return false;
    }
    if (this->syncout_marker != other.syncout_marker) {
      return false;
    }
    if (this->filter_mode != other.filter_mode) {
      return false;
    }
    if (this->have_gnss_time_pulse != other.have_gnss_time_pulse) {
      return false;
    }
    if (this->rtk_status != other.rtk_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const XsStatusWord_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct XsStatusWord_

// alias to use template instance with default allocator
using XsStatusWord =
  xsens_mti_ros2_driver::msg::XsStatusWord_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_mti_ros2_driver

#endif  // XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__STRUCT_HPP_
