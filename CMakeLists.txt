cmake_minimum_required(VERSION 3.19)
project(Ex1)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Ex1
        osm.cpp
        osm.h)
