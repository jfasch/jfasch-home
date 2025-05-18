ADD_EXECUTABLE(
  c++11-array-suite

  array.cpp
)
TARGET_LINK_LIBRARIES(c++11-array-suite gtest_main)
add_test(NAME c++11-array-suite COMMAND c++11-array-suite)
