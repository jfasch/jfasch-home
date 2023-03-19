ADD_EXECUTABLE(
  cxx-exercises-hal--suite

  timer-oneshot-suite.cpp
  timer-periodic-suite.cpp

  fileutil-suite.cpp
  )

TARGET_LINK_LIBRARIES(
  cxx-exercises-hal--suite

  hal
  cxx-exercises-fixtures
  gtest_main 
  )





