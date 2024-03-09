cmake_minimum_required(VERSION 3.5)
project(mobileNum)

add_executable(mobileNum mobileNum.cpp)

set_target_properties(
        mobileNum PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)