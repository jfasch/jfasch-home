ADD_EXECUTABLE(
  cxx-exercises-sensors-core--suite

  sensor-const-suite-basic.cpp
  sensor-random-suite-basic.cpp

  sensor-const-suite-is-a-sensor.cpp
  sensor-random-suite-is-a-sensor.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensors-core--suite

  cxx-exercises-sensors-core
  gtest_main 
)
