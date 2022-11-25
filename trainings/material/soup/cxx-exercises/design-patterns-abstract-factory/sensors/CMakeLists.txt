ADD_LIBRARY(
  cxx-exercises-design-patterns-abstract-factory-sensors

  sensor-i2c-factory.h

  sensor-i2c-factory-vendor1.h
  sensor-i2c-factory-vendor1.cpp

  sensor-i2c-factory-vendor2.h
  sensor-i2c-factory-vendor2.cpp
)  

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-design-patterns-abstract-factory-sensors

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-abstract-factory-sensors

  cxx-exercises-sensors-core-i2c
)
