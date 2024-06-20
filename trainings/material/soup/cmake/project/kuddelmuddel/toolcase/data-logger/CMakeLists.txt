add_library(
  data-logger

  data-logger.cpp
  data-logger.h
  sensor-config.h
  sensor-values.h
  sink-file.h
  sink-logger.h
  sink-mock.h
  sink-terminal.h
)
target_link_libraries(data-logger base)
target_include_directories(data-logger INTERFACE .)
install(TARGETS data-logger DESTINATION lib)
install(
  FILES   

  data-logger.h
  sensor-config.h
  sensor-values.h
  sink-file.h
  sink-logger.h
  sink-mock.h
  sink-terminal.h
  sink-MQTT.h

  DESTINATION include)
