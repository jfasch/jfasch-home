ADD_LIBRARY(
  cxx-exercises-oo-sensor-w1-factory-sensors

  sensor-w1-factory.h
  sensor-w1-factory.cpp
)  

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-oo-sensor-w1-factory-sensors
  
  PUBLIC
  .)

TARGET_LINK_LIBRARIES(
  cxx-exercises-oo-sensor-w1-factory-sensors 

  cxx-exercises-oo-sensor-w1-sensors )
