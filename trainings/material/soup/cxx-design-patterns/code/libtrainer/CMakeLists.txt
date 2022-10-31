ADD_LIBRARY(
  design-patterns-trainer

  sensor.h
  sensor-random.h
  sensor-const.h
  sensor-i2c.h
  sensor-i2c-vendor1.h
  sensor-i2c-vendor2.h

  sensor-A.h
  sensor-A-const.h

  sensor-utils.h
  queue.h
  server-thread.h
  server-thread.cpp

  social-db.h
  social-db.cpp
)  

TARGET_INCLUDE_DIRECTORIES(design-patterns-trainer PUBLIC .)
