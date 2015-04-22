# Copyright: ASROB 2015 (C) Robotics Society of the Universidad Carlos III de Madrid
#     (http://asrob.uc3m.es) RD Project

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)#

# Exporting dependencies for RD1Config.cmake quite manually for now... 
set(RD1_LIBRARIES ${RD1_LIBRARIES} RaspiYarp CACHE INTERNAL "appended libraries") 
# IMPORTANT: RaspiYarp pwmbot works, but pwmbot RaspiYarp fails.

yarp_begin_plugin_library(RaspiYarp)
add_subdirectory(pwmbot)
add_subdirectory(DoubleHBridge)
yarp_end_plugin_library(RaspiYarp)

install(TARGETS RaspiYarp DESTINATION lib)

if(ENABLE_launchRaspiYarp)
  yarp_add_plugin_library_executable(launchRaspiYarp RaspiYarp)
  install(TARGETS launchRaspiYarp DESTINATION bin)
endif(ENABLE_launchRaspiYarp)

