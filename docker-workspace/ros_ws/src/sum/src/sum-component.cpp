#include "sum-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Sum::Sum(std::string const& name) :
    TaskContext(name),
    dataReady1(false),
    dataReady2(false),
    data1(0),
    data2(0)
{
    ports()->addEventPort("simpleIn1",simpleIn1).doc("[double] Input 1");
    ports()->addEventPort("simpleIn2",simpleIn2).doc("[double] Input 2");

    ports()->addPort("simpleOut",simpleOut).doc("[double] Output");
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
    double value;
    if(simpleIn1.read(value) == RTT::NewData)  {
        dataReady1 = true;
        data1 = value;
    }
    if(simpleIn2.read(value) == RTT::NewData)  {
        dataReady2 = true;
        data2 = value;
    }
    if(dataReady1 && dataReady2) {
        dataReady1 = false;
        dataReady2 = false;
        simpleOut.write( data1 + data2 );
    }
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
