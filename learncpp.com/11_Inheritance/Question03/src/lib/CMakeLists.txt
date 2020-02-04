add_library(lib Creature.cpp Player.cpp Monster.cpp)
target_include_directories(lib
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  )
