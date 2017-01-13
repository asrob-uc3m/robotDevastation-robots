# Copyright: (C) 2016 ASROB
# Author: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

find_package(YARP REQUIRED)

yarp_prepare_device(LaserTowerOfDeathController
                    TYPE rd::LaserTowerOfDeathController
                    INCLUDE LaserTowerOfDeathController.hpp
                    WRAPPER RdRobotServer)

IF (NOT SKIP_LaserTowerOfDeathController)

    include_directories( ${YARP_INCLUDE_DIRS} ${ROBOT_DEVASTATION_ROBOTS_INCLUDE_DIRS} )

    yarp_add_plugin(LaserTowerOfDeathController LaserTowerOfDeathController.cpp DeviceDriverImpl.cpp )

    TARGET_LINK_LIBRARIES(LaserTowerOfDeathController ${YARP_LIBRARIES} serial)

    yarp_install(TARGETS LaserTowerOfDeathController
                 EXPORT YARP
                 COMPONENT runtime
                 LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
                 ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR})

    yarp_install(FILES LaserTowerOfDeathController.ini
                 COMPONENT runtime
                 DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR})

ENDIF (NOT SKIP_LaserTowerOfDeathController)

