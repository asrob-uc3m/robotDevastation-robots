# Copyright: ASROB 2015 (C) Robotics Society of the Universidad Carlos III de Madrid
#     (http://asrob.uc3m.es) RD Project

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)

option(ENABLE_RdRobotServer "Enable/disable compilation of RdRobotServer" TRUE)
option(ENABLE_RdFakeMotors "Enable/disable compilation of RdFakeMotors" TRUE)
option(ENABLE_RdOnePwmMotors "Enable/disable compilation of RdOnePwmMotors" TRUE)
option(ENABLE_RdTwoPwmMotors "Enable/disable compilation of RdTwoPwmMotors" TRUE)
option(ENABLE_RdSerialClient "Enable/disable compilation of RdSerialClient" TRUE)
option(ENABLE_EcroWheelController "Enable/disable compilation of EcroWheelController" TRUE)

#yarp_begin_plugin_library(YarpPlugins)
add_subdirectory(RdRobotServer)
add_subdirectory(RdFakeMotors)
add_subdirectory(RdOnePwmMotors)
add_subdirectory(RdTwoPwmMotors)
add_subdirectory(RdSerialClient)
add_subdirectory(EcroWheelController)
#yarp_end_plugin_library(YarpPlugins)

