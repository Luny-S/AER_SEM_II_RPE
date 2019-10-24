#include <sinwave/boost/WorkaroundDouble.h>
#include <rtt/types/TypekitPlugin.hpp>
#include <rtt/types/StructTypeInfo.hpp>
#include <rtt/types/PrimitiveSequenceTypeInfo.hpp>
#include <rtt/types/CArrayTypeInfo.hpp>
#include <vector>

// Note: we need to put these up-front or we get gcc compiler warnings:
// <<warning: type attributes ignored after type is already defined>>        
template class RTT_EXPORT RTT::internal::DataSource< sinwave::WorkaroundDouble >;
template class RTT_EXPORT RTT::internal::AssignableDataSource< sinwave::WorkaroundDouble >;
template class RTT_EXPORT RTT::internal::AssignCommand< sinwave::WorkaroundDouble >;
template class RTT_EXPORT RTT::internal::ValueDataSource< sinwave::WorkaroundDouble >;
template class RTT_EXPORT RTT::internal::ConstantDataSource< sinwave::WorkaroundDouble >;
template class RTT_EXPORT RTT::internal::ReferenceDataSource< sinwave::WorkaroundDouble >;
template class RTT_EXPORT RTT::OutputPort< sinwave::WorkaroundDouble >;
template class RTT_EXPORT RTT::InputPort< sinwave::WorkaroundDouble >;
template class RTT_EXPORT RTT::Property< sinwave::WorkaroundDouble >;
template class RTT_EXPORT RTT::Attribute< sinwave::WorkaroundDouble >;
template class RTT_EXPORT RTT::Constant< sinwave::WorkaroundDouble >;

namespace rtt_roscomm {
  using namespace RTT;
    // Factory function
    
      void rtt_ros_addType_sinwave_WorkaroundDouble() {
           // Only the .msg type is sent over ports. The msg[] (variable size) and  cmsg[] (fixed size) exist only as members of larger messages
           RTT::types::Types()->addType( new types::StructTypeInfo<sinwave::WorkaroundDouble>("/sinwave/WorkaroundDouble") );
           RTT::types::Types()->addType( new types::PrimitiveSequenceTypeInfo<std::vector<sinwave::WorkaroundDouble> >("/sinwave/WorkaroundDouble[]") );
           RTT::types::Types()->addType( new types::CArrayTypeInfo<RTT::types::carray<sinwave::WorkaroundDouble> >("/sinwave/cWorkaroundDouble[]") );
      }

    
}

