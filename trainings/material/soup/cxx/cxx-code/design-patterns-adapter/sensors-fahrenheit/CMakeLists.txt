ADD_LIBRARY(
  cxx-exercises-design-patterns-adapter-sensors-fahrenheit

  sensor-fahrenheit.h

  sensor-fahrenheit-const.h
  sensor-fahrenheit-const.cpp
)  

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-design-patterns-adapter-sensors-fahrenheit 

  PUBLIC
  .)
