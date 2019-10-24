#include "absolute-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Absolute::Absolute(std::string const& name) : TaskContext(name){
  std::cout << "Absolute constructed !" <<std::endl;
}

bool Absolute::configureHook(){
  std::cout << "Absolute configured !" <<std::endl;
  return true;
}

bool Absolute::startHook(){
  std::cout << "Absolute started !" <<std::endl;
  return true;
}

void Absolute::updateHook(){
  std::cout << "Absolute executes updateHook !" <<std::endl;
}

void Absolute::stopHook() {
  std::cout << "Absolute executes stopping !" <<std::endl;
}

void Absolute::cleanupHook() {
  std::cout << "Absolute cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Absolute)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Absolute)
