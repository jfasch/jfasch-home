ADD_LIBRARY(
  cxx-exercises-design-patterns-proxy-sensors

  sensor-round.h
  sensor-remote.h
  sensor-remote.cpp
  sensor-remote-adapter.h
  sensor-remote-adapter.cpp
)  

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-design-patterns-proxy-sensors

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-proxy-sensors

  cxx-exercises-utilities
  cxx-exercises-sensors-core
)
