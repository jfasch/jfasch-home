ADD_EXECUTABLE(
  cxx-exercises-sensors-core--suite

  sensor-const-basic.cpp
  sensor-random-basic.cpp
  sensor-mock-basic.cpp

  sensor-const-is-a-sensor.cpp
  sensor-random-is-a-sensor.cpp
  sensor-mock-is-a-sensor.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensors-core--suite

  cxx-exercises-sensors-core
  gtest_main 
)
