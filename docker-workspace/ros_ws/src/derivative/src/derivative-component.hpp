#ifndef OROCOS_DERIVATIVE_COMPONENT_HPP
#define OROCOS_DERIVATIVE_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Derivative : public RTT::TaskContext{
  public:
    Derivative(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
#endif
