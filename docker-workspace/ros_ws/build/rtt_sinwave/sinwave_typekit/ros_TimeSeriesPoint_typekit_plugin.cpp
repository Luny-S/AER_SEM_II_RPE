#include <sinwave/boost/TimeSeriesPoint.h>
#include <rtt/types/TypekitPlugin.hpp>
#include <rtt/types/StructTypeInfo.hpp>
#include <rtt/types/PrimitiveSequenceTypeInfo.hpp>
#include <rtt/types/CArrayTypeInfo.hpp>
#include <vector>

// Note: we need to put these up-front or we get gcc compiler warnings:
// <<warning: type attributes ignored after type is already defined>>        
template class RTT_EXPORT RTT::internal::DataSource< sinwave::TimeSeriesPoint >;
template class RTT_EXPORT RTT::internal::AssignableDataSource< sinwave::TimeSeriesPoint >;
template class RTT_EXPORT RTT::internal::AssignCommand< sinwave::TimeSeriesPoint >;
template class RTT_EXPORT RTT::internal::ValueDataSource< sinwave::TimeSeriesPoint >;
template class RTT_EXPORT RTT::internal::ConstantDataSource< sinwave::TimeSeriesPoint >;
template class RTT_EXPORT RTT::internal::ReferenceDataSource< sinwave::TimeSeriesPoint >;
template class RTT_EXPORT RTT::OutputPort< sinwave::TimeSeriesPoint >;
template class RTT_EXPORT RTT::InputPort< sinwave::TimeSeriesPoint >;
template class RTT_EXPORT RTT::Property< sinwave::TimeSeriesPoint >;
template class RTT_EXPORT RTT::Attribute< sinwave::TimeSeriesPoint >;
template class RTT_EXPORT RTT::Constant< sinwave::TimeSeriesPoint >;

namespace rtt_roscomm {
  using namespace RTT;
    // Factory function
    
      void rtt_ros_addType_sinwave_TimeSeriesPoint() {
           // Only the .msg type is sent over ports. The msg[] (variable size) and  cmsg[] (fixed size) exist only as members of larger messages
           RTT::types::Types()->addType( new types::StructTypeInfo<sinwave::TimeSeriesPoint>("/sinwave/TimeSeriesPoint") );
           RTT::types::Types()->addType( new types::PrimitiveSequenceTypeInfo<std::vector<sinwave::TimeSeriesPoint> >("/sinwave/TimeSeriesPoint[]") );
           RTT::types::Types()->addType( new types::CArrayTypeInfo<RTT::types::carray<sinwave::TimeSeriesPoint> >("/sinwave/cTimeSeriesPoint[]") );
      }

    
}

