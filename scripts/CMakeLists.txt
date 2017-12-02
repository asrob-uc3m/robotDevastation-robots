# Copyright: UC3M 2016
# Author: ASROB
# CopyPolicy: Released under the terms of the GNU GPL v2.0.
# 

#find_package(YARP REQUIRED)
#list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
#include(YarpInstallationHelpers)
#yarp_configure_external_installation(robotDevastation-robots)

# Install services for autostart
IF(INSTALL_SERVICES)
    install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/etc/service/launchCamera/run
            DESTINATION /etc/service/launchCamera)
    install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/etc/service/launchRobot/run
            DESTINATION /etc/service/launchRobot)
ENDIF()
