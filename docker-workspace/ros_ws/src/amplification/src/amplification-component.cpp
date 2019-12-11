#include "amplification-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Amplification::Amplification(std::string const& name) : TaskContext(name), gain(1) {
    ports()->addEventPort("simpleIn",simpleIn).doc("[double] Input");
    ports()->addEventPort("gainIn",gainIn).doc("[double] Input allowing for gain value changing from another component during runtime");
    ports()->addPort("simpleOut",simpleOut).doc("[double] Output");
    addAttribute("Gain", gain);

    std::cout << "Amplification constructed !" <<std::endl;
}

bool Amplification::configureHook(){
  std::cout << "Amplification configured !" <<std::endl;
  return true;
}

bool Amplification::startHook(){
  std::cout << "Amplification started !" <<std::endl;
  return true;
}

void Amplification::updateHook(){
    double value;
    if(gainIn.read(value) == RTT::NewData){
        gain = value;
        std::cout << "Gain value changed to: " << gain << std::endl;
    } else if(simpleIn.read(value) == RTT::NewData){
        simpleOut.write( gain*value );
    }
}

void Amplification::stopHook() {
  std::cout << "Amplification executes stopping !" <<std::endl;
}

void Amplification::cleanupHook() {
  std::cout << "Amplification cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Amplification)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Amplification)
