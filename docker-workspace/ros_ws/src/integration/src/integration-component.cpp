#include "integration-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Integration::Integration(std::string const& name) :
    TaskContext(name),
    lastTimestamp(0),
    lastValue(0),
    _initialValue(0),
    _priority(1),
    _period(0.01),
    _cpu_affinity(1),
    _cnt(0) {

    ports()->addEventPort("simpleIn",simpleIn).doc("[double] Input");
    ports()->addPort("simpleOut",simpleOut).doc("[double] Output");
    addAttribute("initialValue", _initialValue);

    std::cout << "Integration constructed !" <<std::endl;
}

bool Integration::configureHook(){
    return true;
}


bool Integration::startHook(){
  sumOfValues=_initialValue;
  std::cout << "Integration started !" <<std::endl;
  return true;
}

void Integration::updateHook(){
    //double timestamp = (double)(_cnt++) * _period;
    double value = 0;

    if(simpleIn.read(value) == RTT::NewData){
        sumOfValues += 0.01 * (value + lastValue) / 2;
        // sumOfValues += (timestamp - lastTimestamp) * (value + lastValue) / 2;
        // sumOfValues += value * (timestamp - lastTimestamp);
        simpleOut.write( sumOfValues );

        // lastTimestamp = timestamp;
        lastValue = value;
    }
}

void Integration::stopHook() {
  std::cout << "Integration executes stopping !" <<std::endl;
}

void Integration::cleanupHook() {
  std::cout << "Integration cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Integration)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Integration)
