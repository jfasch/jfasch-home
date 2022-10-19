ADD_EXECUTABLE(
  singleton-social-insurance-inflexible-main

  singleton-social-insurance-inflexible-main.cpp

  social-insurance-inflexible.h
  social-insurance-inflexible.cpp
)

ADD_EXECUTABLE(
  singleton-social-insurance-flexible-main

  singleton-social-insurance-flexible-main.cpp

  social-insurance-flexible.h
  social-insurance-flexible.cpp

  social-insurance-svs.h
  social-insurance-svs.cpp

  social-insurance-oegk.h
  social-insurance-oegk.cpp
)

ADD_EXECUTABLE(
  singleton-social-insurance-flexible-strict-main

  singleton-social-insurance-flexible-strict-main.cpp

  social-insurance-flexible-strict.h
  social-insurance-flexible-strict.cpp

  social-insurance-svs-strict.h
  social-insurance-svs-strict.cpp

  social-insurance-oegk-strict.h
  social-insurance-oegk-strict.cpp
)

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

  dummy.cpp  # have to have at least one compiled file in a library

  # </starting point>


  # <exercises>


  # adapter
  sensor-A.h
  sensor-A-adapt-B.h

  # decorator
  sensor-decorated-const.h
  sensor-decorated-const.cpp
  sensor-decorated-random.h
  sensor-decorated-random.cpp


  # </exercises>
)  

ADD_EXECUTABLE(
  design-patterns-c++-exercises-suite

  # <starting point>
  
  sensor-utils-suite.cpp

  # </starting point>

  
  adapter-suite.cpp

  decorator-suite-starting-point.cpp
  decorator-suite-const-sensor-added-functionality.cpp
  decorator-suite-random-sensor-added-functionality.cpp
  decorator-suite-const-sensor-is-a-sensor.cpp
  decorator-suite-random-sensor-is-a-sensor.cpp
  decorator-suite-decorated-used-in-legacy.cpp
)

TARGET_LINK_LIBRARIES(
  design-patterns-c++-exercises-suite gtest_main 

  design-patterns  
  Threads::Threads
)

ADD_EXECUTABLE(
  thread-server-test

  thread-server-test.cpp
)  
TARGET_LINK_LIBRARIES(
  thread-server-test

  design-patterns  
  Threads::Threads
)  
