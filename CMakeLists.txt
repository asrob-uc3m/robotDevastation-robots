# Copyright: Universidad Carlos III de Madrid (C) 2018;
# Authors: ASROB
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)

project(ROBOT_DEVASTATION_ROBOTS NONE)

option(INSTALL_SERVICES "Choose if you want to install Robot Devastation services" ON)

# add main contents
add_subdirectory(share)
add_subdirectory(scripts)

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/template/ROBOT_DEVASTATION_ROBOTSConfigUninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/ROBOT_DEVASTATION_ROBOTSConfigUninstall.cmake" IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/ROBOT_DEVASTATION_ROBOTSConfigUninstall.cmake)
