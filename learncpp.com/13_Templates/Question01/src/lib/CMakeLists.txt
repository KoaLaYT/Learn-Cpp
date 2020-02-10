add_library(lib Pair.cpp Templates.cpp)
target_include_directories(lib
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  )
