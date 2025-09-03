ADD_EXECUTABLE(
  c++03-static-suite

  global-function.cpp
  static-method.cpp
)
TARGET_LINK_LIBRARIES(c++03-static-suite gtest_main)
add_test(NAME c++03-static-suite COMMAND c++03-static-suite)
