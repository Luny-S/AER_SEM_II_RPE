cmake_minimum_required(VERSION 2.8.3)
project(rtt_sinwave)

find_package(catkin REQUIRED COMPONENTS rtt_roscomm)

ros_generate_rtt_typekit(sinwave)
ros_generate_rtt_service_proxies(sinwave)

orocos_generate_package(
  DEPENDS sinwave
  DEPENDS_TARGETS rtt_roscomm  rtt_std_msgs
 rtt_rosgraph_msgs

)
