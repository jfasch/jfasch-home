ADD_LIBRARY(
  hal

  hal.h

  hal-core.h
  hal-core.cpp

  hal-timer.h
  hal-timer.cpp
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
