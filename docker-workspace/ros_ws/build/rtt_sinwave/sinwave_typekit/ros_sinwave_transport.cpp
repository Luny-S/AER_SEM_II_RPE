#include <orocos/sinwave/boost/TimeSeriesPoint.h>
#include <orocos/sinwave/boost/WorkaroundDouble.h>

#include <rtt_roscomm/rtt_rostopic_ros_msg_transporter.hpp>
#include <rtt_roscomm/rostopic.h>
#include <rtt/types/TransportPlugin.hpp>
#include <rtt/types/TypekitPlugin.hpp>

namespace rtt_roscomm {
  using namespace RTT;
    struct ROSsinwavePlugin
      : public types::TransportPlugin
    {
      bool registerTransport(std::string name, types::TypeInfo* ti)
      {
                 if(name == "/sinwave/TimeSeriesPoint") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<sinwave::TimeSeriesPoint>());} else
       if(name == "/sinwave/WorkaroundDouble") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<sinwave::WorkaroundDouble>());} else
 { }
          return false;
      }
      
      std::string getTransportName() const {
          return "ros";
      }
      
      std::string getTypekitName() const {
          return std::string("ros-")+"sinwave";
      }
      std::string getName() const {
          return std::string("rtt-ros-") + "sinwave" + "-transport";
      }

    };
}

ORO_TYPEKIT_PLUGIN( rtt_roscomm::ROSsinwavePlugin )
