add_executable(reciever main.cpp)
find_package(YARP REQUIRED)
target_link_libraries(reciever ${YARP_LIBRARIES})