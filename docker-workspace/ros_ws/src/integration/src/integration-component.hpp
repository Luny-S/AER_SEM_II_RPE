#ifndef OROCOS_INTEGRATION_COMPONENT_HPP
#define OROCOS_INTEGRATION_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/os/TimeService.hpp>
#include <rtt/Time.hpp>

class Integration : public RTT::TaskContext{
public:
    Integration(std::string const& name);
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


    double _initialValue;
    double sumOfValues;
    double lastTimestamp;
    double lastValue;
};
#endif
