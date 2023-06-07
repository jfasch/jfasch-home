ADD_EXECUTABLE(
  cxx-exercises--hysteresis-no-inheritance--suite

  hysteresis-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises--hysteresis-no-inheritance--suite

  cxx-exercises-sensors-core
  gtest_main 
)
