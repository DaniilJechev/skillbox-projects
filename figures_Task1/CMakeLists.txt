cmake_minimum_required(VERSION 3.5)
project(figures)

add_executable(figures figures.cpp)

set_target_properties(
        figures PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)