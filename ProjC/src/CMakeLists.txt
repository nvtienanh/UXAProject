# @author  nvtienanh
set(LIB_HEADERS
  "${CMAKE_CURRENT_BINARY_DIR}/../include/ProjC/Version.h" # Generated header
  ../include/ProjC/World.h   # Normal header
  ../include/ProjC/Student.h # Normal header
)

set(LIB_SOURCES
  World.cpp
  Student.cpp
)

set(APP_HEADERS
    ${LIB_HEADERS}
)

set(APP_SOURCES
  main.cpp
)

# Define two variables in order not to repeat ourselves.
set(LIBRARY_NAME ProjC)

# Define the library
add_library(${LIBRARY_NAME} SHARED ${LIB_SOURCES})

# Set the build version. It will be used in the name of the lib, with corresponding
# symlinks created. SOVERSION could also be specified for api version. 
set_target_properties(${LIBRARY_NAME} PROPERTIES
  VERSION ${VERSION}  # ${VERSION} was defined in the main CMakeLists.
  FRAMEWORK FALSE
  PUBLIC_HEADER "${LIB_HEADERS}" # specify the public headers
)

# Links the target library against the library (libprojBA)
#target_link_libraries(${LIBRARY_NAME} ProjA)

# This is a make target, so you can do a "make projCrunner"
set(APPLICATION_NAME projCrunner)
add_executable(${APPLICATION_NAME} ${APP_SOURCES})

# Links the target exe (projArunner) against the library (libprojA) and other required libraries
target_link_libraries(${APPLICATION_NAME} ${LIBRARY_NAME} ${Boost_PROGRAM_OPTIONS_LIBRARY})

# Says how and where to install software
# Targets:
#   * <prefix>/lib/<libraries>
#   * header location after install: <prefix>/include/<project>/*.h
#   * headers can be included by C++ code `#<project>/Bar.hpp>`
install(TARGETS ${LIBRARY_NAME} ${APPLICATION_NAME}
  EXPORT ${PROJECT_NAME}Targets            # for downstream dependencies
  ARCHIVE DESTINATION lib COMPONENT libs   # static lib
  RUNTIME DESTINATION bin COMPONENT libs   # binaries
  LIBRARY DESTINATION lib COMPONENT libs   # shared lib
  FRAMEWORK DESTINATION bin COMPONENT libs # for mac
  PUBLIC_HEADER DESTINATION include/${PROJECT_NAME} COMPONENT devel   # headers for mac (note the different component -> different package)
  INCLUDES DESTINATION include/${PROJECT_NAME}             # headers
)

