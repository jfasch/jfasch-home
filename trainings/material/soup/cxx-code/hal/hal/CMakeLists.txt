ADD_LIBRARY(
  hal

  hal.h

  hal-core.h
  hal-core.cpp

  timer-interrupt.h
  timer-interrupt.cpp
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
