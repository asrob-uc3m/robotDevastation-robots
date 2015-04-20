# Copyright: (C) 2013 Universidad Carlos III de Madrid
# Author: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

prepare_device(DoubleHBridge TYPE rd::DoubleHBridge INCLUDE DoubleHBridge.hpp WRAPPER controlboardwrapper2)

IF (NOT SKIP_DoubleHBridge)

  find_package(YARP REQUIRED)

  set ( CMAKE_CXX_FLAGS "-fpermissive")

  # Include any directories needed for YARP
  include_directories(${YARP_INCLUDE_DIRS} ${RD1_INCLUDE_DIRS})

  yarp_add_plugin(DoubleHBridge DoubleHBridge.cpp DeviceDriverImpl.cpp IEncodersImpl.cpp IEncodersTimedImpl.cpp IPositionControlImpl.cpp IVelocityControlImpl.cpp pwm.cpp )
  TARGET_LINK_LIBRARIES(DoubleHBridge ${YARP_LIBRARIES})
  #install(TARGETS DoubleHBridge DESTINATION lib)

ENDIF (NOT SKIP_DoubleHBridge)

