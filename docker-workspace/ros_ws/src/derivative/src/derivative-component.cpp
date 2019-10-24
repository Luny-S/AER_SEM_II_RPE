#include "derivative-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Derivative::Derivative(std::string const& name) : TaskContext(name){
  std::cout << "Derivative constructed !" <<std::endl;
}

bool Derivative::configureHook(){
  std::cout << "Derivative configured !" <<std::endl;
  return true;
}

bool Derivative::startHook(){
  std::cout << "Derivative started !" <<std::endl;
  return true;
}

void Derivative::updateHook(){
  std::cout << "Derivative executes updateHook !" <<std::endl;
}

void Derivative::stopHook() {
  std::cout << "Derivative executes stopping !" <<std::endl;
}

void Derivative::cleanupHook() {
  std::cout << "Derivative cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Derivative)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Derivative)
