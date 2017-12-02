# Copyright: ASROB 2015 (C) Robotics Society of the Universidad Carlos III de Madrid
#     (http://asrob.uc3m.es) RD Project

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)

option(ENABLE_RobotClient "Enable/disable compilation of RobotClient" TRUE)
option(ENABLE_RobotServer "Enable/disable compilation of RobotServer" TRUE)
option(ENABLE_FakeMotorController "Enable/disable compilation of FakeMotorController" TRUE)
option(ENABLE_LaserTowerOfDeathController "Enable/disable compilation of LaserTowerOfDeathController" TRUE)
option(ENABLE_EcroWheelController "Enable/disable compilation of EcroWheelController" TRUE)
option(ENABLE_EcroPwmController "Enable/disable compilation of EcroPwmController" TRUE)
option(ENABLE_RaspiOnePwmMotorController "Enable/disable compilation of RaspiOnePwmMotorController" TRUE)
option(ENABLE_RaspiTwoPwmMotorController "Enable/disable compilation of RaspiTwoPwmMotorController" TRUE)
option(ENABLE_PhidgetSpatial "Enable/disable compilation of PhidgetSpatial" FALSE)

#yarp_begin_plugin_library(YarpPlugins)
add_subdirectory(RobotClient)
add_subdirectory(RobotServer)
add_subdirectory(FakeMotorController)
add_subdirectory(LaserTowerOfDeathController)
add_subdirectory(EcroWheelController)
add_subdirectory(EcroPwmController)
add_subdirectory(RaspiOnePwmMotorController)
add_subdirectory(RaspiTwoPwmMotorController)
add_subdirectory(PhidgetSpatial)
#yarp_end_plugin_library(YarpPlugins)

