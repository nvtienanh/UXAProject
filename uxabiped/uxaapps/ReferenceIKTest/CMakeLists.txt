# @author  nvtienanh
#PROJECT ( ReferenceIKTest )

# include external libbary of biped
INCLUDE(${PROJECT_BINARY_DIR}/include/uxabiped/BipedalConfig.cmake)
INCLUDE_DIRECTORIES(${BIPEDAL_INCLUDE_DIRS})

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})


#set ( PROJECT_LINK_LIBS libbipedal.so )
#set ( LIBBIPEDSRCS "/home/tienanh/themarex/libbipedal/src" )
#set ( LIBBIPEDINCS "/home/tienanh/themarex/libbipedal/include" )
#IF(Simox_VISUALIZATION AND Simox_USE_COIN_VISUALIZATION)
#  INCLUDE_DIRECTORIES(${BIPEDAL_INCLUDE_DIRS})
#  INCLUDE_DIRECTORIES(${LIBBIPEDINCS})

#  # the variable "demo_SRCS" contains all .cpp files of this project
#  FILE(GLOB demo_SRCS ${PROJECT_SOURCE_DIR}/ReferenceIKTest.cpp ${PROJECT_SOURCE_DIR}/Window.cpp ${LIBBIPEDSRCS}/pattern/PolynomialFootstepPlaner.cpp ${LIBBIPEDSRCS}/pattern/FootstepPlaner.cpp
#      ${LIBBIPEDSRCS}/utils/Walking.cpp)

#  FILE(GLOB demo_INCS ${PROJECT_SOURCE_DIR}/Window.h)

#  ################################## moc'ing ##############################
#  set(GUI_MOC_HDRS ${PROJECT_SOURCE_DIR}/Window.h)
#  set(GUI_UIS ${PROJECT_SOURCE_DIR}/Window.ui)

#  VirtualRobotQtApplication(${PROJECT_NAME} "${demo_SRCS}" "${demo_INCS}" "${GUI_MOC_HDRS}" "${GUI_UIS}")
##  SimoxQtApplication(${PROJECT_NAME} "${demo_SRCS}" "${demo_INCS}" "${GUI_MOC_HDRS}" "${GUI_UIS}")

#  MESSAGE( STATUS " ** Simox application ${PROJECT_NAME} will be placed into " ${LIBDIR})
##  MESSAGE( STATUS " ** Simox application ${PROJECT_NAME} will be installed into " ${INSTALL_BIN_DIR})

#ENDIF()

file( GLOB_RECURSE HDRS_FILES *.h *.hpp )
file( GLOB_RECURSE SRCS_FILES *.cpp )
file( GLOB_RECURSE UI_FILES *.ui )

qt4_wrap_cpp( MOC_SRCS ${HDRS_FILES} )
qt4_wrap_ui( UI_HDRS ${UI_FILES} )

source_group( "UI Files" FILES ${UI_FILES} )
source_group( "Generated Files" FILES ${MOC_SRCS} ${UI_HDRS} )

add_library( ${PROJECT_NAME} STATIC ${SRCS_FILES} ${UI_FILES} ${HDRS_FILES} ${MOC_SRCS} ${UI_HDRS} )
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} )

