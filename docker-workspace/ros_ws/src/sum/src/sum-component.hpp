#ifndef OROCOS_SUM_COMPONENT_HPP
#define OROCOS_SUM_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Sum : public RTT::TaskContext{
public:
    Sum(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
private:
    RTT::InputPort<double> simpleIn1;
    RTT::InputPort<double> simpleIn2;
    RTT::OutputPort<double> simpleOut;

    double data1;
    double data2;
    bool dataReady1;
    bool dataReady2;
};
#endif
