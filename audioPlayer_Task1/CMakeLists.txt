cmake_minimum_required(VERSION 3.5)
project(audio)

add_executable(audioPlayer audioPlayer.cpp)

set_target_properties(
        audioPlayer PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)