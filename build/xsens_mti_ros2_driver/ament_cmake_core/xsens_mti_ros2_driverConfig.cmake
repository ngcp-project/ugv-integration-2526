# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_xsens_mti_ros2_driver_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED xsens_mti_ros2_driver_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(xsens_mti_ros2_driver_FOUND FALSE)
  elseif(NOT xsens_mti_ros2_driver_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(xsens_mti_ros2_driver_FOUND FALSE)
  endif()
  return()
endif()
set(_xsens_mti_ros2_driver_CONFIG_INCLUDED TRUE)

# output package information
if(NOT xsens_mti_ros2_driver_FIND_QUIETLY)
  message(STATUS "Found xsens_mti_ros2_driver: 1.0.2 (${xsens_mti_ros2_driver_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'xsens_mti_ros2_driver' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${xsens_mti_ros2_driver_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(xsens_mti_ros2_driver_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "rosidl_cmake-extras.cmake;ament_cmake_export_dependencies-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake;rosidl_cmake_export_typesupport_targets-extras.cmake;rosidl_cmake_export_typesupport_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${xsens_mti_ros2_driver_DIR}/${_extra}")
endforeach()
