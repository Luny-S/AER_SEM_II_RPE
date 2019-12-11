#ifndef OROCOS_LOGGER_COMPONENT_HPP
#define OROCOS_LOGGER_COMPONENT_HPP

#include <rtt/os/TimeService.hpp>
#include <rtt/Time.hpp>
#include <rtt/RTT.hpp>
#include <iomanip>

#include <sinwave/TimeSeriesPoint.h>
#include <sinwave/WorkaroundDouble.h> // Jak to naprawić? Float64 ROSowe jako typ wiadomosci


class Logger : public RTT::TaskContext{
public:
    Logger(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();

private:
    RTT::InputPort<double> simpleIn;
    RTT::InputPort<sinwave::TimeSeriesPoint> complexIn;
    // RTT::OutputPort<double> rosSimpleOut;
    RTT::OutputPort<sinwave::WorkaroundDouble> rosSimpleOut;
    RTT::OutputPort<sinwave::TimeSeriesPoint> rosComplexOut;
    int cycles;
    bool _verbose;

    bool _simple_in_active;
    bool _complex_in_active;
    bool _simple_ros_out_active;
    bool _complex_ros_out_active;

};
#endif
