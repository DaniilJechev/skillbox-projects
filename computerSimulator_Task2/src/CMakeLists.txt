cmake_minimum_required(VERSION 3.5)
project(computer)

add_executable(computer main.cpp)

set_target_properties(
        computer PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        computer
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(computer cpu disk gpu ram kbd)