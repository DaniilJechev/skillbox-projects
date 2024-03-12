cmake_minimum_required(VERSION 3.5)
project(desktop)

add_executable(desktop desktop.cpp)

set_target_properties(
        desktop PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)