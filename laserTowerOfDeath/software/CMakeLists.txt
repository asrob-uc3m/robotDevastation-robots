# Copyright: ASROB 2015 (C) Robotics Society of the Universidad Carlos III de Madrid
#     (http://asrob.uc3m.es) RD Project

# Reduce warning level with cmake 2.6
cmake_minimum_required(VERSION 2.6)
# Cmake policies
if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)#

# Exporting dependencies for RD_RASPIConfig.cmake quite manually for now... 
set(RD_RASPI_LIBRARIES ${RD_RASPI_LIBRARIES} LaserTowerOfDeathYarp CACHE INTERNAL "appended libraries") 
# IMPORTANT: RaspiYarp pwmbot works, but pwmbot RaspiYarp fails.

option(ENABLE_LaserTowerOfDeathYarp_LaserTowerOfDeath "Choose if you want to compile LaserTowerOfDeathYarp_LaserTowerOfDeath" TRUE)

yarp_begin_plugin_library(LaserTowerOfDeathYarp)
add_subdirectory(LaserTowerOfDeath)
yarp_end_plugin_library(LaserTowerOfDeathYarp)

install(TARGETS LaserTowerOfDeathYarp DESTINATION lib)


option(ENABLE_launchLaserTowerOfDeathYarp "Choose if you want to compile launchLaserTowerOfDeathYarp" TRUE)

if(ENABLE_launchLaserTowerOfDeathYarp)
  yarp_add_plugin_yarpdev_executable(launchLaserTowerOfDeathYarp LaserTowerOfDeathYarp)
  install(TARGETS launchLaserTowerOfDeathYarp DESTINATION bin)
endif(ENABLE_launchLaserTowerOfDeathYarp)

