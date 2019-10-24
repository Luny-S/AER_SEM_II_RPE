#include "sum-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Sum::Sum(std::string const& name) : TaskContext(name){
  std::cout << "Sum constructed !" <<std::endl;
}

bool Sum::configureHook(){
  std::cout << "Sum configured !" <<std::endl;
  return true;
}

bool Sum::startHook(){
  std::cout << "Sum started !" <<std::endl;
  return true;
}

void Sum::updateHook(){
  std::cout << "Sum executes updateHook !" <<std::endl;
}

void Sum::stopHook() {
  std::cout << "Sum executes stopping !" <<std::endl;
}

void Sum::cleanupHook() {
  std::cout << "Sum cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Sum)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Sum)
