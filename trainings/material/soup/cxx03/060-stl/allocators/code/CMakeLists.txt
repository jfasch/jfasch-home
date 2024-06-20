ADD_EXECUTABLE(
  c++11-allocator-suite

  basic.cpp
)
TARGET_LINK_LIBRARIES(c++11-allocator-suite gtest_main)

add_test(NAME c++11-allocator-suite COMMAND c++11-allocator-suite)
