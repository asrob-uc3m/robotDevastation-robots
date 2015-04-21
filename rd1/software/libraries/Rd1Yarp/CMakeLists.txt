# Copyright: ASROB 2015 (C) Robotics Society of the Universidad Carlos III de Madrid
#     (http://asrob.uc3m.es) RD Project

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)#

# Exporting dependencies for RD1Config.cmake quite manually for now... 
set(RD1_LIBRARIES ${RD1_LIBRARIES} Rd1Yarp CACHE INTERNAL "appended libraries") 
# IMPORTANT: Rd1Yarp pwmbot works, but pwmbot Rd1Yarp fails.

yarp_begin_plugin_library(Rd1Yarp)
add_subdirectory(pwmbot)
add_subdirectory(DoubleHBridge)
yarp_end_plugin_library(Rd1Yarp)

install(TARGETS Rd1Yarp DESTINATION lib)

if(ENABLE_launchRd1Yarp)
  yarp_add_plugin_library_executable(launchRd1Yarp Rd1Yarp)
  install(TARGETS launchRd1Yarp DESTINATION bin)
endif(ENABLE_launchRd1Yarp)

