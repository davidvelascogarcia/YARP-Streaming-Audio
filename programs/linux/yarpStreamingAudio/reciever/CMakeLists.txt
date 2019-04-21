# yarpStreamingAudio: Reciever
add_executable(yarpStreamingAudioReciever main.cpp)
find_package(YARP REQUIRED)
target_link_libraries(yarpStreamingAudioReciever ${YARP_LIBRARIES})
