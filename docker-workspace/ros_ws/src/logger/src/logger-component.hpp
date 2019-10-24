#ifndef OROCOS_LOGGER_COMPONENT_HPP
#define OROCOS_LOGGER_COMPONENT_HPP

#include <rtt/os/TimeService.hpp>
#include <rtt/Time.hpp>
#include <rtt/RTT.hpp>
#include <sinwave/TimeSeriesPoint.h>
#include <iomanip>

class Logger : public RTT::TaskContext{
public:
    Logger(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();

private:
    RTT::InputPort<double> simpleInput;
    RTT::InputPort<sinwave::TimeSeriesPoint> complexInput;
    RTT::OutputPort<double> rosOutSimple;
    RTT::OutputPort<sinwave::TimeSeriesPoint> rosOutComplex;
    int cycles;
    bool _verbose;

    bool _simple_in_active;
    bool _complex_in_active;
    bool _simple_ros_out_active;
    bool _complex_ros_out_active;

};
#endif
