# Copyright: ASROB 2015 (C) Robotics Society of the Universidad Carlos III de Madrid
#     (http://asrob.uc3m.es) RD Project
#
# Authors:
# <a href="https://plus.google.com/+davidestevezfernandez">David Estevez</a> (2014-present),
# <a href="http://roboticslab.uc3m.es/roboticslab/people/jg-victores">Juan G. Victores</a> (2012-present),
#
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

# Reduce warning level with cmake 2.6
cmake_minimum_required(VERSION 2.6)
# Cmake policies
if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(rd1)

include(YarpPlugin)#
### options: force default
option(ENABLE_Rd1Yarp_pwmbot "Enable/disable compilation of Rd1Yarp_pwmbot" TRUE)

yarp_begin_plugin_library(Rd1Yarp)
add_subdirectory(emptybot)
add_subdirectory(pwmbot)
yarp_end_plugin_library(Rd1Yarp)
add_executable(launchRd1 main.cpp LaunchRd1.cpp)

target_link_libraries(launchRd1 ${YARP_LIBRARIES})
target_link_libraries(launchRd1 Rd1Yarp)
install(TARGETS launchRd1 DESTINATION bin)

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/template/RD1ConfigUninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/RD1ConfigUninstall.cmake" IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/RD1ConfigUninstall.cmake)

