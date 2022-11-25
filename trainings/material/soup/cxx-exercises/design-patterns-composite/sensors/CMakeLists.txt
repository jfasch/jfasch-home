ADD_LIBRARY(
  cxx-exercises-design-patterns-composite-sensors

  sensor-avg.h
  sensor-avg.cpp
)  

TARGET_INCLUDE_DIRECTORIES(cxx-exercises-design-patterns-composite-sensors PUBLIC .)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-composite-sensors

  cxx-exercises-sensors-core
)
