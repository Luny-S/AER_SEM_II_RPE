#ifndef OROCOS_SUM_COMPONENT_HPP
#define OROCOS_SUM_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Sum : public RTT::TaskContext{
  public:
    Sum(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
#endif
