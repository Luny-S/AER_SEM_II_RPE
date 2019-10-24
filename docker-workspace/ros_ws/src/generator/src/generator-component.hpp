#ifndef OROCOS_GENERATOR_COMPONENT_HPP
#define OROCOS_GENERATOR_COMPONENT_HPP


#include <rtt/RTT.hpp>
#include <rtt/Port.hpp>
#include <cmath>

#include <sinwave/TimeSeriesPoint.h>
#include <sinwave/WorkaroundDouble.h> // Jak to naprawić? Float64 ROSowe jako typ wiadomosci

class Generator : public RTT::TaskContext{
  public:
    Generator(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();

private:
	RTT::OutputPort<sinwave::TimeSeriesPoint> rosOut;
  RTT::OutputPort<sinwave::TimeSeriesPoint> complexOut;
  RTT::OutputPort<double> simpleOut;
  // RTT::OutputPort<double> rosSimpleOut;
  RTT::OutputPort<sinwave::WorkaroundDouble> rosSimpleOut;

  void _setSineFrequency(double frequency);

	double _a;
	double _omega;
	int _cnt;
	int _priority;
	double _period;
	unsigned int _cpu_affinity;

  bool _simple_out_active;
  bool _complex_out_active;
  bool _simple_ros_out_active;
  bool _complex_ros_out_active;
};
#endif
