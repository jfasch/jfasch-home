if (SQLite3_FOUND)
  set(inc_sink_sqlite3 sink-sqlite3.h)
  set(src_sink_sqlite3 sink-sqlite3.cpp)
endif()  
if (Mosquitto_FOUND)
  set(inc_sink_mqtt sink-mqtt.h)
  set(src_sink_mqtt sink-mqtt.cpp)
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
    sink-composite.h
    ${inc_sink_sqlite3}
    ${inc_sink_mqtt}

  SOURCES

    data-logger.cpp
    sensor-config.cpp
    measurements.cpp
    sink-file.cpp
    sink-terminal.cpp
    sink-composite.cpp
    ${src_sink_sqlite3}
    ${src_sink_mqtt}
)

target_link_libraries(data-logger base)

if (SQLite3_FOUND)
  target_link_libraries(data-logger SQLite::SQLite3)
endif()
if (Mosquitto_FOUND)
  target_link_libraries(data-logger Mosquitto::Mosquitto)
endif()
