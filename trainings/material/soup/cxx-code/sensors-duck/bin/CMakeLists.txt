ADD_EXECUTABLE(
  cxx-exercises-sensor-const-main

  sensor-const-main.cpp
  )
TARGET_LINK_LIBRARIES(
  cxx-exercises-sensor-const-main

  cxx-exercises-sensors-duck
  )

ADD_EXECUTABLE(
  cxx-exercises-sensor-random-main

  sensor-random-main.cpp
  )
TARGET_LINK_LIBRARIES(
  cxx-exercises-sensor-random-main

  cxx-exercises-sensors-duck
  )
