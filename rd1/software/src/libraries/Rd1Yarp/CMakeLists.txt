# Copyright: ASROB 2015 (C) Robotics Society of the Universidad Carlos III de Madrid
#     (http://asrob.uc3m.es) RD Project

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)#

yarp_begin_plugin_library(Rd1Yarp)
add_subdirectory(emptybot)
add_subdirectory(pwmbot)
yarp_end_plugin_library(Rd1Yarp)

