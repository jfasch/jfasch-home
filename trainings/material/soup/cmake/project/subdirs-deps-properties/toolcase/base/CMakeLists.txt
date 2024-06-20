add_library(
  base

  sensor.h
  sensor-const.h
  sensor-const.cpp
  sensor-mock.h
  sensor-mock.cpp
  sensor-random.h
  sensor-random.cpp
  sensor-avg.h
  sensor-avg.cpp
  sensor-w1.h
  sensor-w1.cpp

  switch.h
  switch-mock.h
  switch-mock.cpp
  sysfs-switch.h
  sysfs-switch.cpp

  hysteresis.h
  hysteresis.cpp
)

target_include_directories(base INTERFACE .)

install(TARGETS base DESTINATION lib)
install(
  FILES

  sensor.h
  sensor-const.h
  sensor-mock.h
  sensor-random.h
  sensor-avg.h
  sensor-w1.h

  switch.h
  switch-mock.h
  sysfs-switch.h

  hysteresis.h

  DESTINATION include)
