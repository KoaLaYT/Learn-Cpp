add_library(lib Apple.cpp Banana.cpp Fruit.cpp GrannySmith.cpp)
target_include_directories(lib
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  )
