cmake_minimum_required(VERSION 3.5)
project(components)


#add_library(cpu cpu.h cpu.cpp)
#add_library(disk disk.h disk.cpp)
#add_library(gpu gpu.h gpu.cpp)
#add_library(kbd kbd.h kbd.cpp)
#add_library(ram ram.h ram.cpp)

set(TARGETS
        cpu
        disk
        gpu
        kbd
        ram
)

foreach (target ${TARGETS})
    add_library(${target} STATIC)

    set_target_properties(
            ${target} PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
    )

    target_include_directories(
            ${target}
            PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/../src
    )

    target_sources(${target} PRIVATE ${target}.cpp ${target}.h)
endforeach ()