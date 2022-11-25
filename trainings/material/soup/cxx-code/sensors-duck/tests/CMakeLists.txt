ADD_EXECUTABLE(
  cxx-exercises-sensors-duck--suite

  sensor-const-suite-basic.cpp
  sensor-random-suite-basic.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensors-duck--suite

  cxx-exercises-sensors-duck
  gtest_main 
)
