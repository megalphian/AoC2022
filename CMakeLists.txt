cmake_minimum_required(VERSION 3.20)
project(AoC2022)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(AoC2022
        src/main.cpp
        src/day5.cpp
        src/day1.cpp
        include/day5.h
        include/day1.h src/day1.cpp)
