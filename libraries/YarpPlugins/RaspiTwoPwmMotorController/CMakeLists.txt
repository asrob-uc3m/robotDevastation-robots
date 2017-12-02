# Copyright: (C) 2016 ASROB
# Author: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

find_package(YARP REQUIRED)

yarp_prepare_plugin(RaspiTwoPwmMotorController
                    CATEGORY device
                    TYPE rd::RaspiTwoPwmMotorController
                    INCLUDE RaspiTwoPwmMotorController.hpp
                    WRAPPER RobotServer)

IF (NOT SKIP_RaspiTwoPwmMotorController)

    include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ${YARP_INCLUDE_DIRS} ${ROBOT_DEVASTATION_ROBOTS_INCLUDE_DIRS} )

    yarp_add_plugin(RaspiTwoPwmMotorController RaspiTwoPwmMotorController.cpp DeviceDriverImpl.cpp )

    TARGET_LINK_LIBRARIES(RaspiTwoPwmMotorController ${YARP_LIBRARIES})

    yarp_install(TARGETS RaspiTwoPwmMotorController
                 EXPORT YARP
                 COMPONENT runtime
                 LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
                 ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR})

    yarp_install(FILES RaspiTwoPwmMotorController.ini
                 COMPONENT runtime
                 DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR})

ENDIF (NOT SKIP_RaspiTwoPwmMotorController)

