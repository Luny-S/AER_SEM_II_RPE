#include "power-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Power::Power(std::string const& name) : TaskContext(name){
  std::cout << "Power constructed !" <<std::endl;
}

bool Power::configureHook(){
  std::cout << "Power configured !" <<std::endl;
  return true;
}

bool Power::startHook(){
  std::cout << "Power started !" <<std::endl;
  return true;
}

void Power::updateHook(){
  std::cout << "Power executes updateHook !" <<std::endl;
}

void Power::stopHook() {
  std::cout << "Power executes stopping !" <<std::endl;
}

void Power::cleanupHook() {
  std::cout << "Power cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Power)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Power)
