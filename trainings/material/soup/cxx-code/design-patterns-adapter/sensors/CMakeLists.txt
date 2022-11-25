ADD_LIBRARY(
  cxx-exercises-design-patterns-adapter-sensors

  sensor-fahrenheit-adapter.h
  sensor-fahrenheit-adapter.cpp
)  

TARGET_INCLUDE_DIRECTORIES(cxx-exercises-design-patterns-adapter-sensors PUBLIC .)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-adapter-sensors

  cxx-exercises-design-patterns-adapter-sensors-fahrenheit
  cxx-exercises-sensors-core
)
