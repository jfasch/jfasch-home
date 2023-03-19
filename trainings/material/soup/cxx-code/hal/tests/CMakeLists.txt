ADD_EXECUTABLE(
  cxx-exercises-hal--suite

  oo-oneshot-timer-suite.cpp
  oo-periodic-timer-suite.cpp
  )

TARGET_LINK_LIBRARIES(
  cxx-exercises-hal--suite

  hal
  gtest_main 
  )





