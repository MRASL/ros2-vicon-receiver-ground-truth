// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vicon_receiver:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__POSITION__TRAITS_HPP_
#define VICON_RECEIVER__MSG__DETAIL__POSITION__TRAITS_HPP_

#include "vicon_receiver/msg/detail/position__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const vicon_receiver::msg::Position & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x_trans
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_trans: ";
    value_to_yaml(msg.x_trans, out);
    out << "\n";
  }

  // member: y_trans
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_trans: ";
    value_to_yaml(msg.y_trans, out);
    out << "\n";
  }

  // member: z_trans
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_trans: ";
    value_to_yaml(msg.z_trans, out);
    out << "\n";
  }

  // member: x_rot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_rot: ";
    value_to_yaml(msg.x_rot, out);
    out << "\n";
  }

  // member: y_rot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_rot: ";
    value_to_yaml(msg.y_rot, out);
    out << "\n";
  }

  // member: z_rot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_rot: ";
    value_to_yaml(msg.z_rot, out);
    out << "\n";
  }

  // member: w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w: ";
    value_to_yaml(msg.w, out);
    out << "\n";
  }

  // member: segment_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "segment_name: ";
    value_to_yaml(msg.segment_name, out);
    out << "\n";
  }

  // member: subject_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "subject_name: ";
    value_to_yaml(msg.subject_name, out);
    out << "\n";
  }

  // member: frame_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_number: ";
    value_to_yaml(msg.frame_number, out);
    out << "\n";
  }

  // member: translation_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "translation_type: ";
    value_to_yaml(msg.translation_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const vicon_receiver::msg::Position & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<vicon_receiver::msg::Position>()
{
  return "vicon_receiver::msg::Position";
}

template<>
inline const char * name<vicon_receiver::msg::Position>()
{
  return "vicon_receiver/msg/Position";
}

template<>
struct has_fixed_size<vicon_receiver::msg::Position>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vicon_receiver::msg::Position>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vicon_receiver::msg::Position>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VICON_RECEIVER__MSG__DETAIL__POSITION__TRAITS_HPP_
