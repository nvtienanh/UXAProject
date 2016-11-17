project( QT4_GUI )
cmake_minimum_required( VERSION 2.8.3 )

find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )
#include_directories( ${PROJECT_SOURCE_DIR}/src )
#include_directories( ${PROJECT_BINARY_DIR}/src )

#configure_file(
#    "${PROJECT_SOURCE_DIR}/Configs.h.in"
#    "${PROJECT_BINARY_DIR}/Configs.h" )

add_subdirectory( src )
add_subdirectory( test )
add_subdirectory( doc )
add_subdirectory( include )
