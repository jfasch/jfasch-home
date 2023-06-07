ADD_EXECUTABLE(
  cxx-exercises-sensors-core--suite

  # using the tests from "nopoly" which still hold
  ../../sensors-core-nopoly/tests/sensor-const-suite-basic.cpp
  ../../sensors-core-nopoly/tests/sensor-random-suite-basic.cpp

  sensor-const-suite-is-a-sensor.cpp
  sensor-random-suite-is-a-sensor.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensors-core--suite

  cxx-exercises-sensors-core
  gtest_main 
)
