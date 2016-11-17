# include external libbary of biped
INCLUDE(${PROJECT_BINARY_DIR}/include/uxapanel/BipedalConfig.cmake)
INCLUDE_DIRECTORIES(${BIPEDAL_INCLUDE_DIRS})

set(APPLICATION_NAME uxabipedrunner)

#add_library(${APPLICATION_NAME} SHARED IMPORTED GLOBAL)

## It's important to specify the full path to the library you want to import
#set_target_properties(${APPLICATION_NAME} PROPERTIES IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libuxabiped.so")

#add_executable( ${APPLICATION_NAME} main.cpp )
#target_link_libraries( ${APPLICATION_NAME} ${QT_LIBRARIES} uxapanel)
setupSimoxExternalLibraries()
ADD_EXECUTABLE(${APPLICATION_NAME} main.cpp)
TARGET_LINK_LIBRARIES(${APPLICATION_NAME} VirtualRobot uxapanel)
