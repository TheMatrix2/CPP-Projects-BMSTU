cmake_minimum_required(VERSION 3.25)
project(lab_6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_6
        main.cpp TimeClass.cpp TimeClass.h)