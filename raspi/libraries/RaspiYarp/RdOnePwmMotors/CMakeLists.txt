# Copyright: (C) 2013 Universidad Carlos III de Madrid
# Author: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

prepare_device(RdOnePwmMotors TYPE rd::RdOnePwmMotors INCLUDE RdOnePwmMotors.hpp WRAPPER controlboardwrapper2)

IF (NOT SKIP_RdOnePwmMotors)

  find_package(YARP REQUIRED)

  set ( CMAKE_CXX_FLAGS "-fpermissive")

  # Include any directories needed for YARP
  include_directories(${YARP_INCLUDE_DIRS} ${RD_RASPI_INCLUDE_DIRS})

  yarp_add_plugin(RdOnePwmMotors RdOnePwmMotors.cpp DeviceDriverImpl.cpp pwm.cpp )
  TARGET_LINK_LIBRARIES(RdOnePwmMotors ${YARP_LIBRARIES})
  #install(TARGETS RdOnePwmMotors DESTINATION lib)

ENDIF (NOT SKIP_RdOnePwmMotors)

