add_library(
  base

  hysteresis.h
  hysteresis.cpp
  sensor-avg.cpp
  sensor-avg.h
  sensor-const.cpp
  sensor-const.h
  sensor.h
  sensor-mock.cpp
  sensor-mock.h
  sensor-random.cpp
  sensor-random.h
  sensor-w1.h
  switch.h
  switch-mock.cpp
  switch-mock.h
  sysfs-switch.cpp
  sysfs-switch.h

  # MQTT
  MQTT.h
  MQTT_mock.h
  MQTT_publisher.cpp
  MQTT_publisher.h
)

target_include_directories(base INTERFACE .)
target_link_libraries(base Mosquitto::Mosquitto)

install(TARGETS base DESTINATION lib)
install(
  FILES

  hysteresis.h
  sensor-avg.h
  sensor-const.h
  sensor.h
  sensor-mock.h
  sensor-random.h
  sensor-w1.h
  switch.h
  switch-mock.h
  sysfs-switch.h

  MQTT.h
  MQTT_mock.h
  MQTT_publisher.h

  DESTINATION include)
