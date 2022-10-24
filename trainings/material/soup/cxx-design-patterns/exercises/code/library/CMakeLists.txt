ADD_LIBRARY(
  design-patterns

  # <starting point>

  sensor.h
  sensor-random.h
  sensor-const.h
  sensor-i2c.h
  sensor-i2c-vendor1.h
  sensor-i2c-vendor2.h

  sensor-utils.h
  queue.h
  server-thread.h
  server-thread.cpp

  social-db.h
  social-db.cpp

  # </starting point>


  # <exercises>

  # adapter
  sensor-A.h
  sensor-A-adapt-B.h

  # decorator
  sensor-decorated.h  
  sensor-decorated-const.h
  sensor-decorated-const.cpp
  sensor-decorated-random.h
  sensor-decorated-random.cpp

  # proxy
  sensor-round.h
  sensor-remote.h
  sensor-remote.cpp
  sensor-remote-adapter.h
  sensor-remote-adapter.cpp

  # composite
  sensor-avg.h
  sensor-avg.cpp

  # command
  social-db-commands.h
  social-db-commands.cpp

  # interpreter
  expression.h
  expression.cpp

  # interpreter/sensor adapter
  expression-sensorvalue.h
  expression-sensorvalue.cpp

  # abstract factory
  sensor-i2c-factory-vendor1.h
  sensor-i2c-factory-vendor1.cpp
  sensor-i2c-factory-vendor2.h
  sensor-i2c-factory-vendor2.cpp

  # </exercises>
)  

TARGET_INCLUDE_DIRECTORIES(design-patterns PUBLIC .)
