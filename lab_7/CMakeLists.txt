cmake_minimum_required(VERSION 3.22)
project(lab_7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(async
        main1_1.cpp)
target_link_libraries(async PRIVATE pthread)

add_executable(future
        main1_2.cpp)
target_link_libraries(future PRIVATE pthread)

add_executable(mutex
        main2.cpp)
target_link_libraries(mutex PRIVATE pthread)

add_executable(mutex-g
        main3.cpp)
target_link_libraries(mutex-g PRIVATE pthread)

add_executable(con-var
        main4.cpp)
target_link_libraries(con-var PRIVATE pthread)