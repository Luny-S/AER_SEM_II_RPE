#ifndef OROCOS_ABSOLUTE_COMPONENT_HPP
#define OROCOS_ABSOLUTE_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Absolute : public RTT::TaskContext{
public:
    Absolute(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
private:
    RTT::InputPort<double> simpleIn;
    RTT::OutputPort<double> simpleOut;
};
#endif
