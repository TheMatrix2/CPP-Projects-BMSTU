cmake_minimum_required(VERSION 3.24)
project(lab_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_4
        Deposit.cpp
        Deposit.h
        main.cpp)

add_executable(test test.cpp)
