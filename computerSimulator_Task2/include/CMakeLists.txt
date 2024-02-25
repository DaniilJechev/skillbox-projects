cmake_minimum_required(VERSION 3.5)
project(components)

set(TARGETS
        cpu
        disk
        gpu
        kbd
        ram
)

foreach (target ${TARGETS})
    add_library(${target} STATIC
            ${target}.h
            ${CMAKE_SOURCE_DIR}/src/${target}.cpp
    )

    set_target_properties(
            ${target} PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
    )
endforeach ()