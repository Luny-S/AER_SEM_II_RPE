#include "logger-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Logger::Logger(std::string const& name) :
		TaskContext(name),
    rosOut("TimeSeriesPoint_out"),
		_verbose(false){

		this->addPort(rosOut).doc("Complex generator output to ROS topic");
		ports()->addEventPort("complexInput", complexInput).doc("TimeSeriesPoint input");

		addAttribute("verbose", _verbose);

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
		sinwave::TimeSeriesPoint msg;
		if(_verbose) { std::cout << std::fixed; }

		if(complexInput.read(msg) == RTT::NewData){
				rosOut.write(msg);
				if(_verbose) {
						std::cout << "[C]\t";
						std::cout << "TIME:\t" << std::setprecision(1) << msg.timestamp;
						std::cout << ",\t VALUE:\t" << std::setprecision(3) << std::setw(6) << msg.value << std::endl;
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
