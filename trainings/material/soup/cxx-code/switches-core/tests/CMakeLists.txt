ADD_EXECUTABLE(
  cxx-exercises-switches-core--suite

  switch-mock-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-switches-core--suite

  cxx-exercises-switches-core
  gtest_main 
)
