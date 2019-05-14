cmake_minimum_required(VERSION 3.10)
project(Lab11-12)

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
find_package(Qt5PrintSupport)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}_autogen/include)

add_executable(${CMAKE_PROJECT_NAME} WIN32
        main.cpp
        ${headerFiles}
        ${sourceFiles}
        )
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets Qt5::PrintSupport)