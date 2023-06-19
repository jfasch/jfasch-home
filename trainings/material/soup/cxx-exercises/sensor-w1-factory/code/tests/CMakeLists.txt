ADD_EXECUTABLE(
  cxx-exercises-oo-sensor-w1-factory--suite

  sensor-w1-factory-suite--basic.cpp
  sensor-w1-factory-suite--notfound.cpp
  sensor-w1-factory-suite--find_is_const.cpp
  )

TARGET_LINK_LIBRARIES(
  cxx-exercises-oo-sensor-w1-factory--suite

  cxx-exercises-oo-sensor-w1-factory-sensors
  cxx-exercises-fixtures

  gtest_main 
  )
