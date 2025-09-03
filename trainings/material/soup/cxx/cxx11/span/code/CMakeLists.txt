add_executable(
  c++11-span-suite

  basic_usage.cpp
  is_a_range.cpp
  compiletime.cpp
  runtime.cpp
  static_extent.cpp
  dynamic_extent.cpp
)
target_link_libraries(c++11-span-suite gtest_main)
add_test(NAME c++11-span-suite COMMAND c++11-span-suite)
