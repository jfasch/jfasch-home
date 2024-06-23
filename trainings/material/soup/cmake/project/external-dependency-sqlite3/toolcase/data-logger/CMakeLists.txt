my_add_library(
  NAME data-logger

  PUBLIC_HEADERS

    data-logger.h
    sensor-config.h
    measurements.h
    sink.h
    sink-file.h
    sink-terminal.h
    sink-sqlite3.h

  SOURCES

    data-logger.cpp
    sensor-config.cpp
    measurements.cpp
    sink-file.cpp
    sink-terminal.cpp
    sink-sqlite3.cpp
)

target_link_libraries(data-logger base)
target_link_libraries(data-logger SQLite::SQLite3)
