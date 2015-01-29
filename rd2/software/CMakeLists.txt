# Copyright: (C) 2015 ASROB
# Author: Juan G Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.8.7)
find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)

yarp_begin_plugin_library(Rd2Yarp)
add_subdirectory(ardubot)
yarp_end_plugin_library(Rd2Yarp)
add_executable(launchRd2 main.cpp LaunchRd2.cpp)

### options: force default
option(ENABLE_Rd2Yarp_ardubot "Enable/disable compilation of Rd2Yarp_ardubot" TRUE)

target_link_libraries(launchRd2 ${YARP_LIBRARIES})
target_link_libraries(launchRd2 Rd2Yarp)
