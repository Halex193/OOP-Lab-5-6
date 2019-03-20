cmake_minimum_required(VERSION 3.10)
project(Lab5_6)

set(CMAKE_CXX_STANDARD 14)

file(GLOB headerFiles "headers/*.h")
file(GLOB sourceFiles "sources/*.cpp")
file(GLOB testFiles "tests/*")

add_executable(Lab5_6
        main.cpp
        ${headerFiles}
        ${sourceFiles}
        )
add_executable(Lab5_6-Tests
        ${testFiles}
        ${headerFiles}
        ${sourceFiles}
        )