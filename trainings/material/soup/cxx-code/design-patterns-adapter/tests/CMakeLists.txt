ADD_EXECUTABLE(
  cxx-exercises-design-patterns-adapter--suite

  adapter-suite-adapter-definitely-knows--a-sensor--HELL.cpp
  adapter-suite-adapter--is-a--sensor.cpp
  adapter-suite-adapter--knows--an-a-sensor.cpp
  adapter-suite-basic.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-adapter--suite

  cxx-exercises-design-patterns-adapter-sensors-fahrenheit
  cxx-exercises-design-patterns-adapter-sensors
  gtest_main 
)





