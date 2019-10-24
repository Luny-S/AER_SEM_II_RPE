// Generated by gencpp from file sinwave/TimeSeriesPoint.msg
// DO NOT EDIT!


#ifndef SINWAVE_MESSAGE_TIMESERIESPOINT_H
#define SINWAVE_MESSAGE_TIMESERIESPOINT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sinwave
{
template <class ContainerAllocator>
struct TimeSeriesPoint_
{
  typedef TimeSeriesPoint_<ContainerAllocator> Type;

  TimeSeriesPoint_()
    : value(0.0)
    , timestamp(0.0)  {
    }
  TimeSeriesPoint_(const ContainerAllocator& _alloc)
    : value(0.0)
    , timestamp(0.0)  {
  (void)_alloc;
    }



   typedef double _value_type;
  _value_type value;

   typedef double _timestamp_type;
  _timestamp_type timestamp;





  typedef boost::shared_ptr< ::sinwave::TimeSeriesPoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sinwave::TimeSeriesPoint_<ContainerAllocator> const> ConstPtr;

}; // struct TimeSeriesPoint_

typedef ::sinwave::TimeSeriesPoint_<std::allocator<void> > TimeSeriesPoint;

typedef boost::shared_ptr< ::sinwave::TimeSeriesPoint > TimeSeriesPointPtr;
typedef boost::shared_ptr< ::sinwave::TimeSeriesPoint const> TimeSeriesPointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sinwave::TimeSeriesPoint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sinwave::TimeSeriesPoint_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace sinwave

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sinwave': ['/workspace/ros_ws/src/sinwave/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::sinwave::TimeSeriesPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sinwave::TimeSeriesPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sinwave::TimeSeriesPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sinwave::TimeSeriesPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sinwave::TimeSeriesPoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sinwave::TimeSeriesPoint_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sinwave::TimeSeriesPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6e0b16802732d370b3f1fc6d31821639";
  }

  static const char* value(const ::sinwave::TimeSeriesPoint_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6e0b16802732d370ULL;
  static const uint64_t static_value2 = 0xb3f1fc6d31821639ULL;
};

template<class ContainerAllocator>
struct DataType< ::sinwave::TimeSeriesPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sinwave/TimeSeriesPoint";
  }

  static const char* value(const ::sinwave::TimeSeriesPoint_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sinwave::TimeSeriesPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 value\n\
float64 timestamp\n\
";
  }

  static const char* value(const ::sinwave::TimeSeriesPoint_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sinwave::TimeSeriesPoint_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.value);
      stream.next(m.timestamp);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TimeSeriesPoint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sinwave::TimeSeriesPoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sinwave::TimeSeriesPoint_<ContainerAllocator>& v)
  {
    s << indent << "value: ";
    Printer<double>::stream(s, indent + "  ", v.value);
    s << indent << "timestamp: ";
    Printer<double>::stream(s, indent + "  ", v.timestamp);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SINWAVE_MESSAGE_TIMESERIESPOINT_H
