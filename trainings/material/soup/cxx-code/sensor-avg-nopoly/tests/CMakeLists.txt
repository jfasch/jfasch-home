ADD_EXECUTABLE(
  cxx-exercises-sensor-avg-nopoly--suite

  sensor-avg-nopoly-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensors-core-nopoly--suite

  cxx-exercises-sensor-avg-nopoly
  cxx-exercises-sensors-core-nopoly
  gtest_main 
)
