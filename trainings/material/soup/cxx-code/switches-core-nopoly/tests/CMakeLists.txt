ADD_EXECUTABLE(
  cxx-exercises-switches-core-nopoly--suite

  switch-mock-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-switches-core-nopoly--suite

  cxx-exercises-switches-core-nopoly
  gtest_main 
)
