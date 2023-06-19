ADD_EXECUTABLE(
  cxx-exercises-switches-core--suite

  switch-mock-basic.cpp
  switch-mock-is-a-switch-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-switches-core--suite

  cxx-exercises-switches-core
  gtest_main 
)
