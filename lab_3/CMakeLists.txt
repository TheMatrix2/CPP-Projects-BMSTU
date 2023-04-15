cmake_minimum_required(VERSION 3.24)
project(lab_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_3
        main.cpp
        Vector_2D.cpp
        Vector_2D.h
        Vector_3D.cpp
        Vector_3D.h)
add_executable(test
        Vector_2D.cpp
        Vector_2D.h
        test.cpp)
