cmake_minimum_required(VERSION 3.10)
project(Question03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic")

add_subdirectory(Io)
list(APPEND EXTRA_LIBS Io)

add_executable(Question03 Main.cpp)

target_link_libraries(Question03 PUBLIC ${EXTRA_LIBS})
