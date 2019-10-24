// Generated by gencpp from file sinwave/WorkaroundDouble.msg
// DO NOT EDIT!


#ifndef SINWAVE_MESSAGE_WORKAROUNDDOUBLE_H
#define SINWAVE_MESSAGE_WORKAROUNDDOUBLE_H


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
struct WorkaroundDouble_
{
  typedef WorkaroundDouble_<ContainerAllocator> Type;

  WorkaroundDouble_()
    : value(0.0)  {
    }
  WorkaroundDouble_(const ContainerAllocator& _alloc)
    : value(0.0)  {
  (void)_alloc;
    }



   typedef double _value_type;
  _value_type value;





  typedef boost::shared_ptr< ::sinwave::WorkaroundDouble_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sinwave::WorkaroundDouble_<ContainerAllocator> const> ConstPtr;

}; // struct WorkaroundDouble_

typedef ::sinwave::WorkaroundDouble_<std::allocator<void> > WorkaroundDouble;

typedef boost::shared_ptr< ::sinwave::WorkaroundDouble > WorkaroundDoublePtr;
typedef boost::shared_ptr< ::sinwave::WorkaroundDouble const> WorkaroundDoubleConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sinwave::WorkaroundDouble_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sinwave::WorkaroundDouble_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::sinwave::WorkaroundDouble_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sinwave::WorkaroundDouble_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sinwave::WorkaroundDouble_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sinwave::WorkaroundDouble_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sinwave::WorkaroundDouble_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sinwave::WorkaroundDouble_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sinwave::WorkaroundDouble_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1b1594d2b74931ef8fe7be8e2d594455";
  }

  static const char* value(const ::sinwave::WorkaroundDouble_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1b1594d2b74931efULL;
  static const uint64_t static_value2 = 0x8fe7be8e2d594455ULL;
};

template<class ContainerAllocator>
struct DataType< ::sinwave::WorkaroundDouble_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sinwave/WorkaroundDouble";
  }

  static const char* value(const ::sinwave::WorkaroundDouble_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sinwave::WorkaroundDouble_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 value\n\
";
  }

  static const char* value(const ::sinwave::WorkaroundDouble_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sinwave::WorkaroundDouble_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WorkaroundDouble_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sinwave::WorkaroundDouble_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sinwave::WorkaroundDouble_<ContainerAllocator>& v)
  {
    s << indent << "value: ";
    Printer<double>::stream(s, indent + "  ", v.value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SINWAVE_MESSAGE_WORKAROUNDDOUBLE_H