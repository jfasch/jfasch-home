ADD_EXECUTABLE(
  cxx-exercises-sensors-core--suite

  sensor-const-suite.cpp
  sensor-random-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensors-core--suite

  cxx-exercises-sensors-core
  gtest_main 
)
