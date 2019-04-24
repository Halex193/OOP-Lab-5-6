cmake_minimum_required(VERSION 3.10)
project(Lab5_6)

set(CMAKE_CXX_STANDARD 14)

file(GLOB headerFiles "headers/*.h")
file(GLOB sourceFiles "sources/*.cpp")
file(GLOB testFiles "tests/*")

file(COPY data DESTINATION .)


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
#include_directories("D:\\Program Files\\MySQL\\MySQL Connector C++ 1.1.12\\include")
#include_directories("D:\\Program Files\\MySQL\\boost_1_55_0")
#link_directories("D:\\Program Files\\MySQL\\MySQL Connector C++ 1.1.12\\lib\\opt")
#target_link_libraries(Lab5_6 "D:\\Program Files\\MySQL\\MySQL Connector C++ 1.1.12\\lib\\opt\\mysqlcppconn.lib")