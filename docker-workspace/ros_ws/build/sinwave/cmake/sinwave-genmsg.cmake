# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "sinwave: 2 messages, 1 services")

set(MSG_I_FLAGS "-Isinwave:/workspace/ros_ws/src/sinwave/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(sinwave_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg" NAME_WE)
add_custom_target(_sinwave_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sinwave" "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg" ""
)

get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg" NAME_WE)
add_custom_target(_sinwave_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sinwave" "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg" ""
)

get_filename_component(_filename "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv" NAME_WE)
add_custom_target(_sinwave_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sinwave" "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv" "sinwave/TimeSeriesPoint"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(sinwave
  "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sinwave
)
_generate_msg_cpp(sinwave
  "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sinwave
)

### Generating Services
_generate_srv_cpp(sinwave
  "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv"
  "${MSG_I_FLAGS}"
  "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sinwave
)

### Generating Module File
_generate_module_cpp(sinwave
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sinwave
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(sinwave_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(sinwave_generate_messages sinwave_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg" NAME_WE)
add_dependencies(sinwave_generate_messages_cpp _sinwave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg" NAME_WE)
add_dependencies(sinwave_generate_messages_cpp _sinwave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv" NAME_WE)
add_dependencies(sinwave_generate_messages_cpp _sinwave_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sinwave_gencpp)
add_dependencies(sinwave_gencpp sinwave_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sinwave_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(sinwave
  "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sinwave
)
_generate_msg_eus(sinwave
  "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sinwave
)

### Generating Services
_generate_srv_eus(sinwave
  "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv"
  "${MSG_I_FLAGS}"
  "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sinwave
)

### Generating Module File
_generate_module_eus(sinwave
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sinwave
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(sinwave_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(sinwave_generate_messages sinwave_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg" NAME_WE)
add_dependencies(sinwave_generate_messages_eus _sinwave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg" NAME_WE)
add_dependencies(sinwave_generate_messages_eus _sinwave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv" NAME_WE)
add_dependencies(sinwave_generate_messages_eus _sinwave_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sinwave_geneus)
add_dependencies(sinwave_geneus sinwave_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sinwave_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(sinwave
  "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sinwave
)
_generate_msg_lisp(sinwave
  "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sinwave
)

### Generating Services
_generate_srv_lisp(sinwave
  "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv"
  "${MSG_I_FLAGS}"
  "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sinwave
)

### Generating Module File
_generate_module_lisp(sinwave
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sinwave
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(sinwave_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(sinwave_generate_messages sinwave_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg" NAME_WE)
add_dependencies(sinwave_generate_messages_lisp _sinwave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg" NAME_WE)
add_dependencies(sinwave_generate_messages_lisp _sinwave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv" NAME_WE)
add_dependencies(sinwave_generate_messages_lisp _sinwave_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sinwave_genlisp)
add_dependencies(sinwave_genlisp sinwave_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sinwave_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(sinwave
  "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sinwave
)
_generate_msg_nodejs(sinwave
  "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sinwave
)

### Generating Services
_generate_srv_nodejs(sinwave
  "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv"
  "${MSG_I_FLAGS}"
  "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sinwave
)

### Generating Module File
_generate_module_nodejs(sinwave
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sinwave
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(sinwave_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(sinwave_generate_messages sinwave_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg" NAME_WE)
add_dependencies(sinwave_generate_messages_nodejs _sinwave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg" NAME_WE)
add_dependencies(sinwave_generate_messages_nodejs _sinwave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv" NAME_WE)
add_dependencies(sinwave_generate_messages_nodejs _sinwave_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sinwave_gennodejs)
add_dependencies(sinwave_gennodejs sinwave_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sinwave_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(sinwave
  "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sinwave
)
_generate_msg_py(sinwave
  "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sinwave
)

### Generating Services
_generate_srv_py(sinwave
  "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv"
  "${MSG_I_FLAGS}"
  "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sinwave
)

### Generating Module File
_generate_module_py(sinwave
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sinwave
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(sinwave_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(sinwave_generate_messages sinwave_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/WorkaroundDouble.msg" NAME_WE)
add_dependencies(sinwave_generate_messages_py _sinwave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/msg/TimeSeriesPoint.msg" NAME_WE)
add_dependencies(sinwave_generate_messages_py _sinwave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/workspace/ros_ws/src/sinwave/srv/AddTwoDataPoints.srv" NAME_WE)
add_dependencies(sinwave_generate_messages_py _sinwave_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sinwave_genpy)
add_dependencies(sinwave_genpy sinwave_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sinwave_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sinwave)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sinwave
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(sinwave_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sinwave)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sinwave
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(sinwave_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sinwave)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sinwave
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(sinwave_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sinwave)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sinwave
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(sinwave_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sinwave)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sinwave\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sinwave
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(sinwave_generate_messages_py std_msgs_generate_messages_py)
endif()
