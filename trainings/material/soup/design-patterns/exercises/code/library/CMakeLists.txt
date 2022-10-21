ADD_LIBRARY(
  design-patterns

  # <starting point>

  sensor.h
  sensor-random.h
  sensor-const.h

  sensor-utils.h
  queue.h
  server-thread.h
  server-thread.cpp

  social-db.h
  social-db.cpp
  social-db-commands.h
  social-db-commands.cpp

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

  # </exercises>
)  

TARGET_INCLUDE_DIRECTORIES(design-patterns PUBLIC .)
