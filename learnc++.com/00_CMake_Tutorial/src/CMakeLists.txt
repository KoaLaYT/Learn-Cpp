cmake_minimum_required(VERSION 3.10)

# set the project name
project(Hello VERSION 2.3)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "use my version of sqrt implementation" ON)

configure_file(HelloConfig.h.in HelloConfig.h)

if (USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif()

# add the executable
add_executable(Hello Main.cpp)

target_link_libraries(Hello PUBLIC ${EXTRA_LIBS})

target_include_directories(Hello PUBLIC
                                "${PROJECT_BINARY_DIR}"
                          )

install(TARGETS Hello DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/HelloConfig.h" DESTINATION include)


enable_testing()

# does the application run
add_test(NAME Runs COMMAND Hello 25)

# does the usage message work?
# add_test(NAME Usage COMMAND Tutorial)
# set_tests_properties(Usage
#  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
# )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
  )
endfunction(do_test)

# do a bunch of result based tests
do_test(Hello 4 "4 is 2")
do_test(Hello 9 "9 is 3")
do_test(Hello 5 "5 is 2.236")
do_test(Hello 7 "7 is 2.645")
do_test(Hello 25 "25 is 5")
do_test(Hello -25 "-25 is [-nan|nan|0]")
do_test(Hello 0.0001 "0.0001 is 0.01")
