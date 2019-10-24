#ifndef OROCOS_AMPLIFICATION_COMPONENT_HPP
#define OROCOS_AMPLIFICATION_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Amplification : public RTT::TaskContext{
  public:
    Amplification(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
#endif
