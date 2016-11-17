# @author  nvtienanh
set(LIB_HEADERS
    "${CMAKE_CURRENT_BINARY_DIR}/../include/qt4-gui/Configs.h" # Generated header
    ../include/qt4-gui/LoadImage.h # Normal header
)

set(LIB_SOURCES
  LoadImage.cpp
)

set(UI_FILES
  LoadImage.ui
)

qt4_wrap_cpp( MOC_SRCS ${LIB_HEADERS} )
qt4_wrap_ui( UI_HDRS ${UI_FILES} )

source_group( "UI Files" FILES ${UI_FILES} )
source_group( "Generated Files" FILES ${MOC_SRCS} ${UI_HDRS} )

# Define two variables in order not to repeat ourselves.
set(LIBRARY_NAME demoqt4gui)

# Define the library
add_library(${LIBRARY_NAME} SHARED ${LIB_SOURCES} ${UI_FILES} ${HDRS_FILES} ${MOC_SRCS} ${UI_HDRS})

# Set the build version. It will be used in the name of the lib, with corresponding
# symlinks created. SOVERSION could also be specified for api version.
set_target_properties(${LIBRARY_NAME} PROPERTIES
  #VERSION ${VERSION}  # ${VERSION} was defined in the main CMakeLists.
  FRAMEWORK FALSE
  PUBLIC_HEADER "${LIB_HEADERS}" # specify the public headers
)

# Says how and where to install software
# Targets:
#   * <prefix>/lib/<libraries>
#   * header location after install: <prefix>/include/<project>/*.h
#   * headers can be included by C++ code `#<project>/Bar.hpp>`
install(TARGETS ${LIBRARY_NAME}
  EXPORT ${PROJECT_NAME}Targets            # for downstream dependencies
  ARCHIVE DESTINATION lib COMPONENT libs   # static lib
  RUNTIME DESTINATION bin COMPONENT libs   # binaries
  LIBRARY DESTINATION lib COMPONENT libs   # shared lib
  FRAMEWORK DESTINATION bin COMPONENT libs # for mac
  PUBLIC_HEADER DESTINATION include/${PROJECT_NAME} COMPONENT devel   # headers for mac (note the different component -> different package)
  INCLUDES DESTINATION include             # headers
)

