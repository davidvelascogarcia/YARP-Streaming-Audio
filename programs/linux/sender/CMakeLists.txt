add_executable(sender main.cpp)
find_package(YARP REQUIRED)
target_link_libraries(sender ${YARP_LIBRARIES})