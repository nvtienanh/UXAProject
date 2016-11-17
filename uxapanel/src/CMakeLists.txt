# @author  nvtienanh
#
# include external libbary of biped
INCLUDE(${PROJECT_BINARY_DIR}/include/uxapanel/BipedalConfig.cmake)

set(APPLICATION_NAME uxabipedrun)
# Setup MOCS QT GUI
set(UI_FILES
  Window.ui
)

set(APP_SOURCES
  main.cpp
  Window.cpp
)

set(APP_HEADERS
    Window.h # Normal header
)

qt4_wrap_cpp( MOC_SRCS ${APP_HEADERS})
qt4_wrap_ui( UI_HDRS ${UI_FILES} )

source_group( "UI Files" FILES ${UI_FILES} )
source_group( "Generated Files" FILES ${MOC_SRCS} ${UI_HDRS})

setupSimoxExternalLibraries()

ADD_EXECUTABLE(${APPLICATION_NAME} ${APP_SOURCES} ${UI_FILES} ${HDRS_FILES} ${MOC_SRCS} ${UI_HDRS})
TARGET_LINK_LIBRARIES(${APPLICATION_NAME} VirtualRobot uxabiped)

# Says how and where to install software
# Targets:
#   * <prefix>/lib/<libraries>
#   * header location after install: <prefix>/include/<project>/*.h
#   * headers can be included by C++ code `#<project>/Bar.hpp>`
install(TARGETS ${APPLICATION_NAME}
  EXPORT ${PROJECT_NAME}Targets            # for downstream dependencies
  ARCHIVE DESTINATION lib COMPONENT libs   # static lib
  RUNTIME DESTINATION bin COMPONENT libs   # binaries
  LIBRARY DESTINATION lib COMPONENT libs   # shared lib
  FRAMEWORK DESTINATION bin COMPONENT libs # for mac
  PUBLIC_HEADER DESTINATION include/${PROJECT_NAME} COMPONENT devel   # headers for mac (note the different component -# > different package)
  INCLUDES DESTINATION include             # headers
)

