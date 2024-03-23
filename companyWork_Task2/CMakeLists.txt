cmake_minimum_required(VERSION 3.5)
project(companyWork)

add_executable(companyWork companyWork.cpp)

set_target_properties(
        companyWork PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)