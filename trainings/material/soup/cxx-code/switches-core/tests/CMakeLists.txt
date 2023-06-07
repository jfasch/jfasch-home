ADD_EXECUTABLE(
  cxx-exercises-switches-core--suite

  # using the tests from "nopoly" which still hold
  ../../switches-core-nopoly/tests/switch-mock-suite.cpp

  switch-mock-is-a-switch-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-switches-core--suite

  cxx-exercises-switches-core
  gtest_main 
)
