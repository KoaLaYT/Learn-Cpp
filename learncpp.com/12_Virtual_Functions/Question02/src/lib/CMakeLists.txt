add_library(lib Shape.cpp Point.cpp Circle.cpp Triangle.cpp)
target_include_directories(lib
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  )
