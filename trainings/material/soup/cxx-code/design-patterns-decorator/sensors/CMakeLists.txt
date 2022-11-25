ADD_LIBRARY(
  cxx-exercises-design-patterns-decorator-sensors

  sensor-decorated.h

  sensor-decorated-const.h
  sensor-decorated-const.cpp

  sensor-decorated-random.h
  sensor-decorated-random.cpp
)  

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-design-patterns-decorator-sensors 

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-decorator-sensors

  cxx-exercises-sensors-core
)
