cmake_minimum_required(VERSION 3.5)
project(elves)

add_executable(elvesVillage elvesVillage.cpp)

set_target_properties(
        elvesVillage PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)