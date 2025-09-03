ADD_EXECUTABLE(
  cxx-exercises-displays-core--suite

  display-null-suite.cpp
  display-console-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-displays-core--suite

  cxx-exercises-displays-core
  gtest_main 
)

add_test(NAME cxx-exercises-displays-core--suite COMMAND cxx-exercises-displays-core--suite)
