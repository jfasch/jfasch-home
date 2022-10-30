ADD_LIBRARY(
  design-patterns-trainee

  trainee-dummy.h
  trainee-dummy.cpp

  # adapter
  sensor-A-adapter.h

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

  # observer
  social-db-observable.h
  social-db-observable.cpp

  # </exercises>
)  

TARGET_INCLUDE_DIRECTORIES(design-patterns-trainee PUBLIC .)
TARGET_LINK_LIBRARIES(design-patterns-trainee design-patterns-trainer)
