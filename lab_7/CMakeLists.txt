cmake_minimum_required(VERSION 3.22)
project(lab_7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(async
        main1.cpp)

add_executable(mutex
        main2.cpp)

add_executable(mutex-g
        main3.cpp)

add_executable(con-var
        main4.cpp)