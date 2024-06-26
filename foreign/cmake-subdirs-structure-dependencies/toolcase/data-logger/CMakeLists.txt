add_library(
  data-logger

  data-logger.cpp
  data-logger.h
  sensor-config.h
  sensor-config.cpp
  measurements.h
  measurements.cpp
  sink.h
  sink-file.h
  sink-file.cpp
  sink-terminal.h
  sink-terminal.cpp
)
target_link_libraries(data-logger base)
target_include_directories(data-logger INTERFACE .)
install(TARGETS data-logger DESTINATION lib)
install(
  FILES   

  data-logger.h
  sensor-config.h
  measurements.h
  sink-file.h
  sink.h
  sink-mock.h
  sink-terminal.h

  DESTINATION include)
