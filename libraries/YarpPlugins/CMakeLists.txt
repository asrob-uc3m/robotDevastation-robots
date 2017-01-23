# Copyright: ASROB 2015 (C) Robotics Society of the Universidad Carlos III de Madrid
#     (http://asrob.uc3m.es) RD Project

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)

option(ENABLE_RobotServer "Enable/disable compilation of RobotServer" TRUE)
option(ENABLE_FakeMotorController "Enable/disable compilation of FakeMotorController" TRUE)
option(ENABLE_LaserTowerOfDeathController "Enable/disable compilation of LaserTowerOfDeathController" TRUE)
option(ENABLE_EcroWheelController "Enable/disable compilation of EcroWheelController" TRUE)
option(ENABLE_RaspiOnePwmMotorController "Enable/disable compilation of RaspiOnePwmMotorController" TRUE)
option(ENABLE_RaspiTwoPwmMotorController "Enable/disable compilation of RaspiTwoPwmMotorController" TRUE)

### macros
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        SET(dirlist ${dirlist} ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(subdir ${SUBDIRS})
    set(ROBOT_DEVASTATION_ROBOTS_INCLUDE_DIRS ${ROBOT_DEVASTATION_ROBOTS_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/${subdir} CACHE INTERNAL "appended header dirs")
ENDFOREACH()

#yarp_begin_plugin_library(YarpPlugins)
add_subdirectory(RobotServer)
add_subdirectory(FakeMotorController)
add_subdirectory(LaserTowerOfDeathController)
add_subdirectory(EcroWheelController)
add_subdirectory(RaspiOnePwmMotorController)
add_subdirectory(RaspiTwoPwmMotorController)
#yarp_end_plugin_library(YarpPlugins)

