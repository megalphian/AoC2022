cmake_minimum_required(VERSION 3.20)
project(AoC2022)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(AoC2022
        main.cpp
        day5.cpp
        include/day5.h)
