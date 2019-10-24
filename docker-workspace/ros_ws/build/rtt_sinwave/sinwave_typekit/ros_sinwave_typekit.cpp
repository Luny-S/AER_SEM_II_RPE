#include <orocos/sinwave/boost/TimeSeriesPoint.h>
#include <orocos/sinwave/boost/WorkaroundDouble.h>

#include <rtt/types/TypekitPlugin.hpp>
#include <rtt/types/StructTypeInfo.hpp>

namespace rtt_roscomm {
  using namespace RTT;

    /** Declare all factory functions */
            void rtt_ros_addType_sinwave_TimeSeriesPoint();
        void rtt_ros_addType_sinwave_WorkaroundDouble();

   
    /**
     * This interface defines the types of the realTime package.
     */
    class ROSsinwaveTypekitPlugin
      : public types::TypekitPlugin
    {
    public:
      virtual std::string getName(){
          return std::string("ros-")+"sinwave";
      }

      virtual bool loadTypes() {
          // call all factory functions
                  rtt_ros_addType_sinwave_TimeSeriesPoint(); // factory function for adding TypeInfo.
        rtt_ros_addType_sinwave_WorkaroundDouble(); // factory function for adding TypeInfo.

          return true;
      }
      virtual bool loadOperators() { return true; }
      virtual bool loadConstructors() { return true; }
    };
}

ORO_TYPEKIT_PLUGIN( rtt_roscomm::ROSsinwaveTypekitPlugin )

