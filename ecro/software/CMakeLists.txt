# Copyright: (C) 2010 RobotCub Consortium
# Author: Paul Fitzpatrick
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.8.7)
find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)

yarp_begin_plugin_library(EcroYarp)
#add_subdirectory(emptybot)
#add_subdirectory(pwmbot)
yarp_end_plugin_library(EcroYarp)
add_executable(launchEcro main.cpp LaunchEcro.cpp)

target_link_libraries(launchEcro ${YARP_LIBRARIES})
target_link_libraries(launchEcro EcroYarp)
