# Copyright: (C) 2013 Universidad Carlos III de Madrid
# Author: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

prepare_device(RdFakeMotors TYPE rd::RdFakeMotors INCLUDE RdFakeMotors.hpp WRAPPER RdRobotServer)

IF (NOT SKIP_RdFakeMotors)

  find_package(YARP REQUIRED)

  set ( CMAKE_CXX_FLAGS "-fpermissive")

  # Include any directories needed for YARP
  include_directories(${YARP_INCLUDE_DIRS} ${RD_RASPI_INCLUDE_DIRS})

  yarp_add_plugin(RdFakeMotors RdFakeMotors.cpp DeviceDriverImpl.cpp )
  TARGET_LINK_LIBRARIES(RdFakeMotors ${YARP_LIBRARIES})
  #install(TARGETS RdFakeMotors DESTINATION lib)

ENDIF (NOT SKIP_RdFakeMotors)

