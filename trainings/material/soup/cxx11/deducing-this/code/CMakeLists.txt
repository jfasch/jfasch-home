add_executable(
  c++11-deducing-this-suite

  basic.cpp
)
target_link_libraries(c++11-deducing-this-suite gtest_main)
add_test(NAME c++11-deducing-this-suite COMMAND c++11-deducing-this-suite)
