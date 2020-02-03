cmake_minimum_required(VERSION 3.10)
project(quiz)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic")

add_subdirectory(lib)
list(APPEND EXTRA_LIBS lib)

add_executable(quiz Main.cpp)

target_link_libraries(quiz PUBLIC ${EXTRA_LIBS})
