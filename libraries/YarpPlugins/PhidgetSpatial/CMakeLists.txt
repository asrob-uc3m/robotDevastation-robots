# Copyright: (C) 2017 ASROB
# Author: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

find_package(YARP REQUIRED)

yarp_prepare_plugin(PhidgetSpatial
                    CATEGORY device
                    TYPE rd::PhidgetSpatial
                    INCLUDE PhidgetSpatial.hpp
                    WRAPPER analogServer)

IF (NOT SKIP_PhidgetSpatial)

    find_package(YARP REQUIRED)

    # Include any directories needed for YARP
    include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${YARP_INCLUDE_DIRS} )

    yarp_add_plugin(PhidgetSpatial PhidgetSpatial.hpp PhidgetSpatial.cpp HelperFuncs.cpp)

    TARGET_LINK_LIBRARIES(PhidgetSpatial ${YARP_LIBRARIES} phidget21)

    yarp_install(TARGETS PhidgetSpatial
                 EXPORT YARP
                 COMPONENT runtime
                 LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
                 ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR})

    yarp_install(FILES PhidgetSpatial.ini
                 COMPONENT runtime
                 DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR})

ENDIF (NOT SKIP_PhidgetSpatial)

