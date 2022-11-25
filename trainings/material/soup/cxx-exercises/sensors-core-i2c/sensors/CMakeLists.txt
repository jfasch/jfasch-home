ADD_LIBRARY(
  cxx-exercises-sensors-core-i2c

  sensor-i2c.h
  sensor-i2c-vendor1.h
  sensor-i2c-vendor1.cpp
  sensor-i2c-vendor2.h
  sensor-i2c-vendor2.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-sensors-core-i2c

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensors-core-i2c

  cxx-exercises-sensors-core
)
