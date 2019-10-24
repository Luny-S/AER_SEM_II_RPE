#ifndef OROCOS_INTEGRATION_COMPONENT_HPP
#define OROCOS_INTEGRATION_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Integration : public RTT::TaskContext{
  public:
    Integration(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
#endif
