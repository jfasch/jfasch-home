ADD_EXECUTABLE(
  cxx-exercises-sensors-core-nopoly--suite

  sensor-const-suite-basic.cpp
  sensor-random-suite-basic.cpp
  sensor-mock-suite-basic.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensors-core-nopoly--suite

  cxx-exercises-sensors-core-nopoly
  gtest_main 
)
