ADD_EXECUTABLE(
  cxx-exercises-hal--suite

  hal-timer-oneshot-suite.cpp
  hal-timer-periodic-suite.cpp

  hal-delay-suite.cpp

  hal-fileutil-suite.cpp
  )

TARGET_LINK_LIBRARIES(
  cxx-exercises-hal--suite

  hal
  cxx-exercises-fixtures
  gtest_main 
  )





