#include "logger-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Logger::Logger(std::string const& name) :
		TaskContext(name),
		rosOutSimple("Double_out"),
		rosOutComplex("TimeSeriesPoint_out"),
		_verbose(false),
		_simple_in_active(false),
		_complex_in_active(false),
		_simple_ros_out_active(false),
		_complex_ros_out_active(false)	{

		ports()->addEventPort("simpleInput", simpleInput).doc("Double input");
		ports()->addEventPort("complexInput", complexInput).doc("TimeSeriesPoint input");

		this->addPort(rosOutSimple).doc("Simple output to ROS topic");
		this->addPort(rosOutComplex).doc("Complex output to ROS topic");

		addAttribute("verbose", _verbose);
		addAttribute("simple_in_active",_simple_in_active);
		addAttribute("complex_in_active",_complex_in_active);
		addAttribute("simple_ros_out_active",_simple_ros_out_active);
		addAttribute("complex_ros_out_active",_complex_ros_out_active);

		std::cout << "Logger constructed !" <<std::endl;
		this->startHook();
}

bool Logger::configureHook(){
  std::cout << "Logger configured !" <<std::endl;
  return true;
}

bool Logger::startHook(){
  std::cout << "Logger started !" <<std::endl;
	cycles = 0;
  return true;
}

void Logger::updateHook(){
		sinwave::TimeSeriesPoint msgComplex;
		double msgSimple;

		if(_verbose) { std::cout << std::fixed; }

		if (_complex_in_active) {
				if(complexInput.read(msgComplex) == RTT::NewData){
						if(_complex_ros_out_active){
								rosOutComplex.write(msgComplex);
						}
						if(_verbose) {
								std::cout << "[C]\t";
								std::cout << "TIME:\t" << std::setprecision(1) << msgComplex.timestamp;
								std::cout << ",\t VALUE:\t" << std::setprecision(3) << std::setw(6) << msgComplex.value << std::endl;
						}
				}
		}

		if (_simple_in_active) {
				if(simpleInput.read(msgSimple) == RTT::NewData){
						if(_simple_ros_out_active){
								rosOutSimple.write(msgSimple);
						}
						if(_verbose) {
								std::cout << "[S]\t";
								std::cout << "VALUE:\t" << std::setprecision(3) << std::setw(6) << msgSimple << std::endl;
						}
				}
		}

}

void Logger::stopHook() {
  std::cout << "Logger executes stopping !" <<std::endl;
}

void Logger::cleanupHook() {
  std::cout << "Logger cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Logger)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Logger)
