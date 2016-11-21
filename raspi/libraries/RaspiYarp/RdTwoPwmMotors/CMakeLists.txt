# Copyright: (C) 2013 Universidad Carlos III de Madrid
# Author: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

yarp_prepare_device(RdTwoPwmMotors TYPE rd::RdTwoPwmMotors INCLUDE RdTwoPwmMotors.hpp WRAPPER RdRobotServer)

IF (NOT SKIP_RdTwoPwmMotors)

  find_package(YARP REQUIRED)

  set ( CMAKE_CXX_FLAGS "-fpermissive")

  # Include any directories needed for YARP
  include_directories(${YARP_INCLUDE_DIRS} ${RD_RASPI_INCLUDE_DIRS})

  yarp_add_plugin(RdTwoPwmMotors RdTwoPwmMotors.cpp DeviceDriverImpl.cpp pwm.cpp )
  TARGET_LINK_LIBRARIES(RdTwoPwmMotors ${YARP_LIBRARIES} wiringPi)
  #install(TARGETS RdTwoPwmMotors DESTINATION lib)

ENDIF (NOT SKIP_RdTwoPwmMotors)

