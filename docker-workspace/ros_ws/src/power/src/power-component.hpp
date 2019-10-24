#ifndef OROCOS_POWER_COMPONENT_HPP
#define OROCOS_POWER_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Power : public RTT::TaskContext{
  public:
    Power(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
#endif
