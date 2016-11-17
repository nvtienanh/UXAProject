# @author  nvtienanh
#
# include external libbary of biped
INCLUDE(${PROJECT_BINARY_DIR}/include/uxabiped/BipedalConfig.cmake)
INCLUDE_DIRECTORIES(${BIPEDAL_INCLUDE_DIRS})


set(LIB_SOURCES

)

set(APPLICATION_NAME demoUXAPanel)

set(APP_HEADERS
    Window.h
)

set(APP_SOURCES
  main.cpp
  Window.cpp
)

set(APP_UI
  Window.ui
)

qt4_wrap_cpp( MOC_SRCS ${APP_HEADERS} )
qt4_wrap_ui( UI_HDRS ${APP_UI} )

source_group( "UI Files" FILES ${APP_UI} )
source_group( "Generated Files" FILES ${MOC_SRCS} ${UI_HDRS} )

setupSimoxExternalLibraries()
ADD_EXECUTABLE(${APPLICATION_NAME} ${APP_SOURCES}  ${APP_UI} ${HDRS_FILES} ${MOC_SRCS} ${UI_HDRS})
TARGET_LINK_LIBRARIES(${APPLICATION_NAME} VirtualRobot ${BIPEDAL_EXTERNAL_LIBRARIES})

