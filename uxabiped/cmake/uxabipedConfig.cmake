#@author nvtienanh
#include("${CMAKE_CURRENT_LIST_DIR}/uxabipedTargets.cmake")
if(UXABIPED_FOUND)
    return()
endif()
set(UXABIPED_FOUND TRUE)

find_package(Simox REQUIRED)
find_package(MMMCore REQUIRED)

# This is a hardcode to add MMMCore libary
# because find_package(MMMCore REQUIRED) may be not works
set (MMMCORE_INCLUDE_DIRS "/usr/local/include/MMM")
set (MMMCORE_LIBRARIES "/usr/local/lib/libMMMCore.so")

set(UXABIPED_INCLUDE_DIRS ${UXABIPED_HEADERS} ${MMMCORE_INCLUDE_DIRS} ${Simox_EXTERNAL_INCLUDE_DIRS} ${Simox_INCLUDE_DIRS} ${EIGEN_INCLUDE_DIRS})
Set(UXABIPED_EXTERNAL_LIBRARIES ${MMMCORE_LIBRARIES} ${Simox_EXTERNAL_LIBRARIES} ${Simox_LIBRARIES})
Set(UXABIPED_LIBRARIES ${UXABIPED_LIB} ${MMMCORE_LIBRARIES} ${Simox_EXTERNAL_LIBRARIES} ${Simox_LIBRARIES})

