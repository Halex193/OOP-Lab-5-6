cmake_minimum_required(VERSION 3.10)
project(Lab5_6)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB headerFiles "headers/*.h")
file(GLOB sourceFiles "sources/*.cpp")
file(GLOB testFiles "tests/*")

file(COPY data DESTINATION .)

find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(Lab5_6 WIN32
        main.cpp
        ${headerFiles}
        ${sourceFiles}
        )
add_executable(Lab5_6-Tests WIN32
        ${testFiles}
        ${headerFiles}
        ${sourceFiles}
		)
target_link_libraries(Lab5_6 Qt5::Widgets)
