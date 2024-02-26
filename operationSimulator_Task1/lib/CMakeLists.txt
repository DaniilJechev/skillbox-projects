cmake_minimum_required(VERSION 3.5)

project(instruments)

add_library(instruments myLib.h myLib.cpp)

set_target_properties(
        instruments PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)