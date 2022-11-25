ADD_EXECUTABLE(
  cxx-exercises-design-patterns-decorator--suite

  decorator-suite-starting-point.cpp
  decorator-suite-const-sensor-added-functionality.cpp
  decorator-suite-random-sensor-added-functionality.cpp
  decorator-suite-const-sensor-is-a-sensor.cpp
  decorator-suite-random-sensor-is-a-sensor.cpp
  decorator-suite-decorated-used-in-legacy.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-decorator--suite

  cxx-exercises-design-patterns-decorator-sensors
  gtest_main 
)





