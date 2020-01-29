cmake_minimum_required(VERSION 3.10)
project(AddSub)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic")

add_executable(AddSub Main.cpp)
