ADD_EXECUTABLE(
  onewire-temperature-monolithic 

  onewire-temperature-monolithic.cpp
  )

ADD_EXECUTABLE(
  onewire-temperature-oo

  onewire-temperature-oo.cpp
  )

TARGET_LINK_LIBRARIES(
  onewire-temperature-oo

  cxx-exercises-oo-sensor-w1-sensors
  )
