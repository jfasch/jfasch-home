ADD_EXECUTABLE(
  cxx-exercises-hal--suite

  timer-interrupt-suite.cpp
  )

TARGET_LINK_LIBRARIES(
  cxx-exercises-hal--suite

  hal
  gtest_main 
  )





