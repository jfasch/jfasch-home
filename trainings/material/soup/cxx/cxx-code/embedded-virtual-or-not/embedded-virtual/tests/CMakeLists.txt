add_executable(
  embedded-virtual-tests

  source-suite.cpp
  sink-suite.cpp
)

target_link_libraries(
  embedded-virtual-tests

  embedded-virtual-toolcase
  gtest_main 
)

add_test(
  NAME embedded-virtual-tests
  COMMAND embedded-virtual-tests
)
