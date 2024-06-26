# Usage:
#
# if (Mosquitto_FOUND)
#    target_link_libraries(MyTarget Mosquitto::Mosquitto)
# endif()

find_path(Mosquitto_INCLUDE_DIR mosquitto.h)
find_library(Mosquitto_LIBRARY NAMES mosquitto)
include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
  Mosquitto 
  FOUND_VAR Mosquitto_FOUND
  REQUIRED_VARS Mosquitto_LIBRARY Mosquitto_INCLUDE_DIR
)

set(Mosquitto_LIBRARIES ${Mosquitto_LIBRARY})

mark_as_advanced(Mosquitto_INCLUDE_DIR Mosquitto_LIBRARY)

add_library(Mosquitto::Mosquitto INTERFACE IMPORTED)
target_link_libraries(Mosquitto::Mosquitto INTERFACE ${Mosquitto_LIBRARIES})
target_include_directories(Mosquitto::Mosquitto INTERFACE ${Mosquitto_INCLUDE_DIR})
