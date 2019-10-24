#ifndef OROCOS_OFFSET_COMPONENT_HPP
#define OROCOS_OFFSET_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Offset : public RTT::TaskContext{
  public:
    Offset(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
#endif
