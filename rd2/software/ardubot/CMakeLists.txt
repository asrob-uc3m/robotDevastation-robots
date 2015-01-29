# Copyright: (C) 2013 Universidad Carlos III de Madrid
# Author: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

prepare_device(ardubot TYPE ArduBot INCLUDE ArduBot.hpp WRAPPER controlboard)

IF (NOT SKIP_ardubot)

  find_package(YARP REQUIRED)

  # Include any directories needed for YARP
  include_directories(${YARP_INCLUDE_DIRS})

  yarp_add_plugin(ardubot ArduBot.cpp IDeviceImpl.cpp IEncoderImpl.cpp IPositionImpl.cpp IVelocityImpl.cpp )
  TARGET_LINK_LIBRARIES(ardubot ${YARP_LIBRARIES})
  #install(TARGETS ardubot DESTINATION lib)

ENDIF (NOT SKIP_ardubot)

