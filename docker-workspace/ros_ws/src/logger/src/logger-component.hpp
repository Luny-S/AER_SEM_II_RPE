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
    RTT::InputPort<sinwave::TimeSeriesPoint> complexInput;
    RTT::OutputPort<sinwave::TimeSeriesPoint> rosOut;
    int cycles;
    bool _verbose;
};
#endif
