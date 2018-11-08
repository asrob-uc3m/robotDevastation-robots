# Copyright: UC3M 2018
# Author: ASROB
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

# Install services for autostart
if(INSTALL_SERVICES)
    install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/etc/service/launchCamera/run
            DESTINATION /etc/service/launchCamera)
    install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/etc/service/launchRobot/run
            DESTINATION /etc/service/launchRobot)
endif()
