cmake_minimum_required(VERSION 3.22)
project(dz_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dz_3
        language.h language.cpp func.h func.cpp main.cpp)
