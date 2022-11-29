cmake_minimum_required(VERSION 3.21)
project(faks3)

set(CMAKE_CXX_STANDARD 14)

add_executable(faks
        ../faks3/main.cpp
        ../faks3/Buffer.h
        ../faks3/Buffer.cpp)
