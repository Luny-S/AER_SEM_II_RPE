#include "offset-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Offset::Offset(std::string const& name) : TaskContext(name), offsetValue(0) {
    ports()->addEventPort("simpleIn",simpleIn).doc("[double] Input");
    ports()->addPort("simpleOut",simpleOut).doc("[double] Output");

    addAttribute("offsetValue",offsetValue);

    std::cout << "Offset constructed !" <<std::endl;
}

bool Offset::configureHook(){
  std::cout << "Offset configured !" <<std::endl;
  return true;
}

bool Offset::startHook(){
  std::cout << "Offset started !" <<std::endl;
  return true;
}

void Offset::updateHook(){
    double value;
    if(simpleIn.read(value) == RTT::NewData){
        simpleOut.write ( value + offsetValue );
    }
}

void Offset::stopHook() {
  std::cout << "Offset executes stopping !" <<std::endl;
}

void Offset::cleanupHook() {
  std::cout << "Offset cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Offset)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Offset)
