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

private:
    RTT::InputPort<double> simpleIn;
    RTT::OutputPort<double> simpleOut;
    RTT::InputPort<double> gainIn;

    double gain;
};
#endif
