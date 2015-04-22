# Copyright: ASROB 2015 (C) Robotics Society of the Universidad Carlos III de Madrid
#     (http://asrob.uc3m.es) RD Project
#
# Authors:
# <a href="https://plus.google.com/+davidestevezfernandez">David Estevez</a> (2014-present),
# <a href="http://roboticslab.uc3m.es/roboticslab/people/jg-victores">Juan G. Victores</a> (2012-present),
#
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

# Reduce warning level with cmake 2.6
cmake_minimum_required(VERSION 2.6)
# Cmake policies
if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(rd1)

##### library options
option(ENABLE_RaspiYarp_pwmbot "Choose if you want to compile RaspiYarp_pwmbot" TRUE)
option(ENABLE_RaspiYarp_DoubleHBridge "Choose if you want to compile RaspiYarp_DoubleHBridge" TRUE)

##### program options
option(ENABLE_launchRaspiYarp "Choose if you want to compile launchRaspiYarp" TRUE)

##### tests options
option(ENABLE_tests "Choose if you want to compile tests" TRUE)

if(MSVC)
  MESSAGE(STATUS "Running on windows")    
  set(CMAKE_DEBUG_POSTFIX "d")
endif(MSVC)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING 
    "Choose the type of build, recommanded options are: Debug or Release")
endif(NOT CMAKE_BUILD_TYPE)
# Hide variable to MSVC users, since it is not needed
if (MSVC)
   mark_as_advanced(CMAKE_BUILD_TYPE)
endif(MSVC)

######################

### this makes everything go in $RD_RASPI_DIR/lib and $RD_RASPI_DIR/bin
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
message(STATUS "Libraries go to ${LIBRARY_OUTPUT_PATH}")
message(STATUS "Executables go to ${EXECUTABLE_OUTPUT_PATH}")
# this doesn't happen automatically for makefiles
make_directory(${LIBRARY_OUTPUT_PATH})
make_directory(${EXECUTABLE_OUTPUT_PATH})
# and let us clean their contents on a "make clean"
##set_directory_properties(PROPERTIES LIBRARY_OUTPUT_PATH ADDITIONAL_MAKE_CLEAN_FILES)
##set_directory_properties(PROPERTIES EXECUTABLE_OUTPUT_PATH ADDITIONAL_MAKE_CLEAN_FILES)
mark_as_advanced(LIBRARY_OUTPUT_PATH EXECUTABLE_OUTPUT_PATH)
mark_as_advanced(CMAKE_BACKWARDS_COMPATIBILITY)
##########################################

# Pick up our scripts - they are all in the cmake conf subdirectory
set(RD_RASPI_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${RD_RASPI_MODULE_PATH})

#set_property(GLOBAL PROPERTY RD_INCLUDE_DIRS)
#set_property(GLOBAL PROPERTY RD_LINK_DIRS)
#set_property(GLOBAL PROPERTY RD_LIBRARIES)
#set_property(GLOBAL PROPERTY RD_TARGETS)
set(RD_RASPI_INCLUDE_DIRS CACHE INTERNAL "appended header dirs" FORCE)
set(RD_RASPI_LINK_DIRS CACHE INTERNAL "appended link dirs" FORCE)
set(RD_RASPI_LIBRARIES CACHE INTERNAL "appended libraries" FORCE)

if(CMAKE_COMPILER_IS_GNUCXX)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage") # enabling coverage
endif(CMAKE_COMPILER_IS_GNUCXX)

# add main contents
add_subdirectory(share)
add_subdirectory(libraries)
add_subdirectory(programs)
if (ENABLE_tests)
#    add_subdirectory(test)
endif (ENABLE_tests)

# export our variables to a RD_RASPIConfig.cmake creation
set(RD_RASPI_LINK_DIRS ${RD_RASPI_LINK_DIRS} ${LIBRARY_OUTPUT_PATH})
configure_file(${CMAKE_SOURCE_DIR}/cmake/template/RD_RASPIConfig.cmake.in
               ${CMAKE_BINARY_DIR}/RD_RASPIConfig.cmake @ONLY)

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/template/RD_RASPIConfigUninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/RD_RASPIConfigUninstall.cmake" IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/RD_RASPIConfigUninstall.cmake)

