ADD_EXECUTABLE(
  cxx-exercises-switches-core-nopoly--suite

  switch-mock-nopoly-basic.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-switches-core-nopoly--suite

  cxx-exercises-switches-core-nopoly
  gtest_main 
)

add_test(NAME cxx-exercises-switches-core-nopoly--suite COMMAND cxx-exercises-switches-core-nopoly--suite)
