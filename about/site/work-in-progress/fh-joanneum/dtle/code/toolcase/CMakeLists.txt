ADD_LIBRARY(
  dtle-toolcase

  hysteresis.h
  hysteresis.cpp

  switch-mock.h
  switch-mock.cpp
  sensor-mock.h
  sensor-mock.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  dtle-toolcase

  PUBLIC
  .
)
