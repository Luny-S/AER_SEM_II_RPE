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
    _rosout_active(false) {

std::cout << "Generator constructed !" <<std::endl;

/*
  PORTS INIT
*/
this->addPort(rosOut).doc("Complex generator output to ROS");
this->ports()->addPort("complexOut", complexOut).doc("TimeSeriesPoint output of the generator");

addAttribute("cnt", _cnt);
addAttribute("a", _a);
addAttribute("omega", _omega);
addAttribute("period",_period);
addAttribute("cpu_affinity",_cpu_affinity);
addAttribute("priority",_priority);
addAttribute("rosout_active",_rosout_active);
// temp_cycles : 1 cycle - 0.01s

addOperation( "setSineFrequency",
              &Generator::_setSineFrequency,
              this, RTT::OwnThread)
              .doc("Sets sine frequency")
              .arg("frequency","New sine frequency");

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
    if(!complexOut.connected() && !rosOut.connected())
    {
    	return false;
    	std::cout << "No output port connected" << std::endl;
    }
    std::cout << "Generator started !" <<std::endl;
    return true;
}

void Generator::updateHook(){
    double time = (double)(_cnt++) * _period;
    sinwave::TimeSeriesPoint msg;
    msg.timestamp = time;
    msg.value = sin( time  * _omega + _a);
    /*
      Generator complex ROS output port message
    */
    if(_rosout_active){
        rosOut.write(msg);
    }
    /*
      Generator complex output
    */
    complexOut.write( msg );
}

void Generator::stopHook() {
  std::cout << "Generator executes stopping !" <<std::endl;
}

void Generator::cleanupHook() {
  std::cout << "Generator cleaning up !" <<std::endl;
}

void Generator::_setSineFrequency(double frequency) {
  this->_omega = 2 * M_PI * frequency;
  std::cout << "Sine frequency changed to " << frequency << " Hz!" << std::endl;
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
