# Copyright: Universidad Carlos III de Madrid (C) 2016
# Authors: ASROB

# Order may be important here
add_subdirectory(ColorDebug)

### macros
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        SET(dirlist ${dirlist} ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(subdir ${SUBDIRS})
    set(ROBOT_DEVASTATION_ROBOTS_INCLUDE_DIRS ${ROBOT_DEVASTATION_ROBOTS_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/${subdir} CACHE INTERNAL "appended header dirs")
ENDFOREACH()

#add_subdirectory(YarpPlugins)

