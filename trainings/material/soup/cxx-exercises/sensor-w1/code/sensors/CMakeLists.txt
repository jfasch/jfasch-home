ADD_LIBRARY(
  cxx-exercises-oo-sensor-w1-sensors

  sensor-w1.h
  sensor-w1.cpp
)  

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-oo-sensor-w1-sensors
  
  PUBLIC
  .)

TARGET_LINK_LIBRARIES(
  cxx-exercises-oo-sensor-w1-sensors 

  cxx-exercises-sensors-core
)
