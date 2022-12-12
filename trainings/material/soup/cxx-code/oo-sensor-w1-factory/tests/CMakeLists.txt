ADD_EXECUTABLE(
  cxx-exercises-oo-sensor-w1-factory--suite

  sensor-w1-factory-suite.cpp
  )

TARGET_LINK_LIBRARIES(
  cxx-exercises-oo-sensor-w1-factory--suite

  cxx-exercises-oo-sensor-w1-factory-sensors
  cxx-exercises-fixtures

  gtest_main 
  )
