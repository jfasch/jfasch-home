ADD_EXECUTABLE(
  cxx-exercises-hal--suite

  oneshot-timer-suite.cpp
  periodic-timer-suite.cpp

  oo-oneshot-timer-suite.cpp
  )

TARGET_LINK_LIBRARIES(
  cxx-exercises-hal--suite

  hal
  gtest_main 
  )





