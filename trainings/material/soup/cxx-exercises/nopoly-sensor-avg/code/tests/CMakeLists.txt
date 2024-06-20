ADD_EXECUTABLE(
  cxx-exercises-sensor-avg-nopoly--suite

  sensor-avg-nopoly-basic.cpp
  sensor-avg-nopoly-change-temperatures.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensor-avg-nopoly--suite

  cxx-exercises-sensor-avg-nopoly
  cxx-exercises-sensors-core-nopoly
  gtest_main 
)

add_test(NAME cxx-exercises-sensor-avg-nopoly--suite COMMAND cxx-exercises-sensor-avg-nopoly--suite)
