add_library(lib FixedPoint2.cpp)
target_include_directories(lib
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  )
