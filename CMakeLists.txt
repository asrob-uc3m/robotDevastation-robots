# Copyright: Universidad Carlos III de Madrid (C) 2019
# Authors: ASROB
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)

project(ROBOT_DEVASTATION_ROBOTS NONE)

# Define custom options.
option(INSTALL_SERVICES "Choose if you want to install Robot Devastation services" ON)

# Find dependencies.
find_package(YCM REQUIRED)
find_package(YARP REQUIRED)

# Load YARP modules.
if(YARP_VERSION_SHORT VERSION_LESS 2.3.70)
    list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
    include(YarpInstallationHelpers)
endif()

# Configure installation paths for YARP resources.
yarp_configure_external_installation(robotDevastation-robots)

# Add main contents.
add_subdirectory(share)
add_subdirectory(scripts)

# Configure and create uninstall target.
include(AddUninstallTarget)
