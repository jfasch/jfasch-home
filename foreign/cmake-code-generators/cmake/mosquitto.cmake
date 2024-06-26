find_package(Mosquitto)     # <--- finds FindMosquitto.cmake in ${CMAKE_MODULE_PATH}

# to be substituted as C macros
if (Mosquitto_FOUND)
  set(CONFIG_HAVE_MOSQUITTO 1)
else()
  set(CONFIG_HAVE_MOSQUITTO 0)
endif()
