#include "integration-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Integration::Integration(std::string const& name) : TaskContext(name){
  std::cout << "Integration constructed !" <<std::endl;
}

bool Integration::configureHook(){
  std::cout << "Integration configured !" <<std::endl;
  return true;
}

bool Integration::startHook(){
  std::cout << "Integration started !" <<std::endl;
  return true;
}

void Integration::updateHook(){
  std::cout << "Integration executes updateHook !" <<std::endl;
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
