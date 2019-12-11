#ifndef OROCOS_DERIVATIVE_COMPONENT_HPP
#define OROCOS_DERIVATIVE_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/os/TimeService.hpp>
#include <rtt/Time.hpp>

class Derivative : public RTT::TaskContext{
public:
    Derivative(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
private:
    RTT::InputPort<double> simpleIn;
    RTT::OutputPort<double> simpleOut;

    int _cnt;
    int _priority;
    double _period;
    unsigned int _cpu_affinity;
    long long _initialTimestamp;

    double lastValue;
    double lastTimestamp;
    double value;
    double timestamp;
};
#endif
