cmake_minimum_required(VERSION 3.25)
project(lab_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_5
        Deposit.cpp
        Deposit.h
        main.cpp)

add_executable(fill filling_input.cpp)