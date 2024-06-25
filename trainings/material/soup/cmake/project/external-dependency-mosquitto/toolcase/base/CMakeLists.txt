my_add_library(
  NAME base 

  PUBLIC_HEADERS

    sensor.h
    sensor-const.h
    sensor-random.h
    sensor-avg.h
    sensor-w1.h
    switch.h
    sysfs-switch.h
    hysteresis.h

  PRIVATE_HEADERS

    file-util.h

  SOURCES

    sensor-const.cpp
    sensor-random.cpp
    sensor-avg.cpp
    sensor-w1.cpp
    sysfs-switch.cpp
    hysteresis.cpp
    file-util.cpp
 )
