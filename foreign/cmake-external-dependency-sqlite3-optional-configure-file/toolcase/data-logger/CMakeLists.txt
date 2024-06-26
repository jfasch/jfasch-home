if (SQLite3_FOUND)
  set(inc_sink_sqlite3 sink-sqlite3.h)
  set(src_sink_sqlite3 sink-sqlite3.cpp)
endif()  

my_add_library(
  NAME data-logger

  PUBLIC_HEADERS

    data-logger.h
    sensor-config.h
    measurements.h
    sink.h
    sink-file.h
    sink-terminal.h
    ${inc_sink_sqlite3}

  SOURCES

    data-logger.cpp
    sensor-config.cpp
    measurements.cpp
    sink-file.cpp
    sink-terminal.cpp
    ${src_sink_sqlite3}
)

target_link_libraries(data-logger base)

if (SQLite3_FOUND)
  target_link_libraries(data-logger SQLite::SQLite3)
endif()
