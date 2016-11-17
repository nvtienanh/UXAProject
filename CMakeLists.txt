# REFERENCE PROJECT CMAKELISTS.TXT
#
# @author  nvtienanh
project(UXAProject)
cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

enable_testing() # needed on top-level CMakeLists.txt

# Target doc definition
# The challenge here is that the sub projects must all define a custom target but with different names to avoid
# conflicts. We also want to be able to issue "make doc" from the top dir while being able to issue "make doc"
# in the subdirs *when* we compile only a subproject.
# We define as well a function AddDocTarget in cmake/DoxygenTarget.cmake
add_custom_target(doc) # DEPENDS docProjA docProjB) Note: with CMake 3.X the DEPENDS would work
ADD_DEPENDENCIES(doc docuxabiped docuxapannel)

#INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/ProjA/include)
#INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/ProjA/include)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/uxabiped/include)
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/uxabiped/include)


INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/uxapanel/include)
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/uxapanel/include)
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/uxapanel/src)

#INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/qt4-gui/include)
#INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/qt4-gui/include)
#INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/qt4-gui/src)

#add_subdirectory(ProjA) # Project A is independent

#add_subdirectory(ProjB) # Project B is depend on Project A

#add_subdirectory(ProjC) # Project C is independent

add_subdirectory(uxabiped) # Project uxabiped is independent

add_subdirectory(uxapanel) # Project uxapanel is depend on Project uxabiped

#add_subdirectory(qt4-gui) # Project C is independent

