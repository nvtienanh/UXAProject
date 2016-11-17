# @author  nvtienanh
#
# include external libbary of biped
INCLUDE(${PROJECT_SOURCE_DIR}/cmake/uxabipedConfig.cmake)

INCLUDE_DIRECTORIES(${UXABIPED_INCLUDE_DIRS})

FILE(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/**/*.cpp)
FILE(GLOB_RECURSE INCS ${PROJECT_SOURCE_DIR}/include/uxabiped/*.h ${PROJECT_SOURCE_DIR}/include/uxabiped/**/*.h)

set(LIB_HEADERS
   ${INCS}
)

set(LIB_SOURCES
   ${SRCS}
)

set(APP_HEADERS

)

set(APP_SOURCES    

)

# Define two variables in order not to repeat ourselves.
set(LIBRARY_NAME uxabiped)

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
target_link_libraries(${LIBRARY_NAME} ${UXABIPED_EXTERNAL_LIBRARIES})

# This is a make target, so you can do a "make projBrunner"
#set(APPLICATION_NAME uxabipedrunner)
#add_executable(${APPLICATION_NAME} ${APP_SOURCES})

# Links the target exe (libbipedrunner) against the library (libbipedal) and other required libraries
#target_link_libraries(${APPLICATION_NAME} ${LIBRARY_NAME} ${Boost_PROGRAM_OPTIONS_LIBRARY})

# Says how and where to install software
# Targets:
#   * <prefix>/lib/<libraries>
#   * header location after install: <prefix>/include/<project>/*.h
#   * headers can be included by C++ code `#<project>/Bar.hpp>`
install(TARGETS ${LIBRARY_NAME}
  EXPORT ${LIBRARY_NAME}Targets DESTINATION cmake         # for downstream dependencies
  ARCHIVE DESTINATION lib COMPONENT libs   # static lib
  RUNTIME DESTINATION bin COMPONENT libs   # binaries
  LIBRARY DESTINATION lib COMPONENT libs   # shared lib
  FRAMEWORK DESTINATION bin COMPONENT libs # for mac
  PUBLIC_HEADER DESTINATION include/${PROJECT_NAME} COMPONENT devel   # headers for mac (note the different component -# > different package)
  INCLUDES DESTINATION include             # headers
)


