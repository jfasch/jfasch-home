ADD_EXECUTABLE(
  design-patterns-c++-exercises-suite

  # <starting point>
  
  sensor-utils-suite.cpp
  server-thread-suite.cpp
  social-db-suite.cpp
  # </starting point>

  
  adapter-suite.cpp

  decorator-suite-starting-point.cpp
  decorator-suite-const-sensor-added-functionality.cpp
  decorator-suite-random-sensor-added-functionality.cpp
  decorator-suite-const-sensor-is-a-sensor.cpp
  decorator-suite-random-sensor-is-a-sensor.cpp
  decorator-suite-decorated-used-in-legacy.cpp

  proxy-round-suite.cpp
  proxy-remote-suite.cpp

  command-suite-insert.cpp
  command-suite-insert-by-base.cpp
  command-suite-find.cpp
  command-suite-drop.cpp
  command-suite-notfound.cpp
  command-suite-notinserted.cpp
  command-suite-bulk-insert.cpp
  command-suite-bulk-insert--std_initializer_list.cpp
)

TARGET_LINK_LIBRARIES(
  design-patterns-c++-exercises-suite gtest_main 

  design-patterns  
  Threads::Threads
)
