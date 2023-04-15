cmake_minimum_required(VERSION 3.24)
project(lab_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(double
        main.cpp
        Vector.cpp
        Vector.hpp)

