# Copyright: (C) 2010 RobotCub Consortium
# Author: Paul Fitzpatrick
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.8.7)
find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})

include(YarpInstallationHelpers)
yarp_configure_external_installation(rd1)
add_subdirectory(share)

include(YarpPlugin)
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

