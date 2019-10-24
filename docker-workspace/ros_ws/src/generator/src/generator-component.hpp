#ifndef OROCOS_GENERATOR_COMPONENT_HPP
#define OROCOS_GENERATOR_COMPONENT_HPP


#include <rtt/RTT.hpp>
#include <cmath>

/*
Powinno być po prostu tak
*/
#include <sinwave/TimeSeriesPoint.h>

/*
Próbowałem narzeźbić ręcznie do tego, co wydaje mi się, że powinno sobie podlinkować,
ale nie działa.
*/
// #include "../../../devel/include/orocos/sinwave/typekit/TimeSeriesPoint.h"


/*
Na tym się nie wywala, ale to chyba nie powinien być ten header.
*/
// #include "../../../devel/include/sinwave/TimeSeriesPoint.h"

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

  void _setSineFrequency(double frequency);

	double _a;
	double _omega;
	int _cnt;
	int _priority;
	double _period;
	unsigned int _cpu_affinity;

  bool _simple_out_active;
  bool _complex_out_active;
  bool _complex_ros_out_active;
};
#endif
