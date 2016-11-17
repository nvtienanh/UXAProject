# This is a make target, so you can do a "make projBrunner"
set(APPLICATION_NAME demoqt4runner)

add_executable( ${APPLICATION_NAME} main.cpp )
target_link_libraries( ${APPLICATION_NAME} ${QT_LIBRARIES} demoqt4gui )
