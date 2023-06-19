ADD_EXECUTABLE(
  cxx-exercises-sensors-core-nopoly--suite

  sensor-const-nopoly-basic.cpp
  sensor-random-nopoly-basic.cpp
  sensor-mock-nopoly-basic.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensors-core-nopoly--suite

  cxx-exercises-sensors-core-nopoly
  gtest_main 
)
