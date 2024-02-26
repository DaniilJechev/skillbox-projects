cmake_minimum_required(VERSION 3.5)

project(operation)

add_executable(src main.cpp)

set_target_properties(
        src PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        src
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)

target_link_libraries(src instruments)