ADD_EXECUTABLE(
  cxx-exercises-hal--suite

  timer-suite.cpp
  )

TARGET_LINK_LIBRARIES(
  cxx-exercises-hal--suite

  hal
  gtest_main 
  )





