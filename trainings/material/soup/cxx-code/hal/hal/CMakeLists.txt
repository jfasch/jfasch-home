ADD_LIBRARY(
  hal

  hal.h

  hal-timer.h
  hal-timer.cpp

  hal-timer-oneshot.h
  hal-timer-oneshot.cpp

  hal-timer-periodic.h
  hal-timer-periodic.cpp

  hal-delay.h
  hal-delay.cpp

  hal-fileutil.h
  hal-fileutil.cpp

  hal-util.h
  hal-util.cpp
)

TARGET_LINK_LIBRARIES(
  hal

  cxx-exercises-utilities
)

TARGET_INCLUDE_DIRECTORIES(
  hal

  PUBLIC
  .
)
