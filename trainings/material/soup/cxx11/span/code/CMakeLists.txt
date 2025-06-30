add_executable(
  c++11-span-suite

  tests.cpp
)
target_link_libraries(c++11-span-suite gtest_main)
add_test(NAME c++11-span-suite COMMAND c++11-span-suite)
