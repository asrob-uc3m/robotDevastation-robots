# Copyright: (C) 2016 ASROB
# Author: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

find_package(YARP REQUIRED)

yarp_prepare_device(RdArduinoClient
                    TYPE rd::RdArduinoClient
                    INCLUDE RdArduinoClient.hpp
                    WRAPPER RdRobotServer)

IF (NOT SKIP_RdArduinoClient)

    include_directories( ${YARP_INCLUDE_DIRS} ${ROBOT_DEVASTATION_ROBOTS_INCLUDE_DIRS} )

    yarp_add_plugin(RdArduinoClient RdArduinoClient.cpp DeviceDriverImpl.cpp )

    TARGET_LINK_LIBRARIES(RdArduinoClient ${YARP_LIBRARIES})

    yarp_install(TARGETS RdArduinoClient
                 EXPORT YARP
                 COMPONENT runtime
                 LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
                 ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR})

    yarp_install(FILES RdArduinoClient.ini
                 COMPONENT runtime
                 DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR})

ENDIF (NOT SKIP_RdArduinoClient)

