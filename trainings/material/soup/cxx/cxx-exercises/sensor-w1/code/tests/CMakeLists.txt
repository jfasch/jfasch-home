ADD_EXECUTABLE(
  cxx-exercises-oo-sensor-w1--suite

  sensor-w1-suite.cpp
  )

TARGET_LINK_LIBRARIES(
  cxx-exercises-oo-sensor-w1--suite

  cxx-exercises-oo-sensor-w1-sensors
  cxx-exercises-fixtures
  gtest_main 
  )

add_test(NAME cxx-exercises-oo-sensor-w1--suite COMMAND cxx-exercises-oo-sensor-w1--suite)




