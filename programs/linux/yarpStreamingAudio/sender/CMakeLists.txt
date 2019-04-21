# yarpStreamingAudio: Sender
add_executable(yarpStreamingAudioSender main.cpp)
find_package(YARP REQUIRED)
target_link_libraries(yarpStreamingAudioSender ${YARP_LIBRARIES})
