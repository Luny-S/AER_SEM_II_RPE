#include "generator-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

//#include <rtt/os/TimeService/hpp>
//#include <rtt/Time.hpp>

Generator::Generator(std::string const& name) :
    TaskContext(name),
    _priority(1),
    _period(0.01),
    _cpu_affinity(1),
    _a(0),
    _omega(1*2*M_PI),
    _cnt(0),
    rosOut("TimeSeriesPoint_out"),
    rosSimpleOut("rosOut"),
    _simple_out_active(false),
    _complex_out_active(false),
    _simple_ros_out_active(false),
    _complex_ros_out_active(false) {

    std::cout << "Generator constructed !" <<std::endl;

    ports()->addPort("simpleOut", simpleOut).doc("Double output of the generator");
    addPort(rosSimpleOut).doc("Simple generator output to ROS");
    ports()->addPort("complexOut", complexOut).doc("TimeSeriesPoint output of the generator");
    addPort(rosOut).doc("Complex generator output to ROS");
    ports()->addPort("setGainOut", setGainOut).doc("Output to set gain in amp component related to sine wave frequency changing");

    addAttribute("cnt", _cnt);
    addAttribute("a", _a);
    addAttribute("omega", _omega);
    addAttribute("period",_period);
    addAttribute("cpu_affinity",_cpu_affinity);
    addAttribute("priority",_priority);

    addAttribute("simple_out_active",_simple_out_active);
    addAttribute("complex_out_active",_complex_out_active);
    addAttribute("simple_ros_out_active",_simple_ros_out_active);
    addAttribute("complex_ros_out_active",_complex_ros_out_active);

    addOperation( "setSineFrequency",
                  &Generator::_setSineFrequency,
                  this, RTT::OwnThread)
                  .doc("Sets sine frequency")
                  .arg("frequency","New sine frequency");
    _initialTimestamp = RTT::os::TimeService::Instance()->getTicks();

    configureHook();
}

bool Generator::configureHook(){
    std::cout << "Configure hook executing!" << std::endl;
    this->setPeriod(_period);

    if(setActivity(new RTT::Activity(ORO_SCHED_RT,
                 _priority,
                 _period,
                 _cpu_affinity,
                 0,
                 getName())) == false){
        std::cout << "Unable to set activity!" << std::endl;
        return false;
    }
    return true;
}


bool Generator::startHook(){
    if( !simpleOut.connected()    &&
        !rosSimpleOut.connected() &&
        !complexOut.connected()   &&
        !rosOut.connected()
        )
    {
      std::cout << "No output port connected" << std::endl;
    	return false;

    }
    std::cout << "Generator started !" <<std::endl;
    return true;
}

void Generator::updateHook(){
    double time = (double)(_cnt++) * _period;
    double value = sin( time  * _omega + _a);

    sinwave::TimeSeriesPoint msg;

    msg.timestamp = time;
    msg.value = value;

    if(_simple_out_active)      { simpleOut.write( value );   }
    // if(_simple_ros_out_active)  { rosSimpleOut.write( value );}

    sinwave::WorkaroundDouble msg2;
    msg2.value = value;
    if(_simple_ros_out_active)  { rosSimpleOut.write( msg2 );}

    if(_complex_out_active)     { complexOut.write( msg );    }
    if(_complex_ros_out_active) { rosOut.write(msg);          }

    // std::cout << "TIMESTAMP:\t" << RTT::os::TimeService::Instance()->secondsSince( _initialTimestamp ) << "\t";
}

void Generator::stopHook() {
  std::cout << "Generator executes stopping !" <<std::endl;
}

void Generator::cleanupHook() {
  std::cout << "Generator cleaning up !" <<std::endl;
}

void Generator::_setSineFrequency(double frequency) {
    this->_omega = 2 * M_PI * frequency;
    double gain = 1 / ( 2 * pow(this->_omega, 3) );
    std::cout << "Sine frequency changed to " << frequency << " Hz!" << std::endl;
    setGainOut.write(gain);
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Generator)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Generator)
