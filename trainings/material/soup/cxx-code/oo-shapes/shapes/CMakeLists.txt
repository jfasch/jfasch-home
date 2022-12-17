ADD_LIBRARY(
  cxx-exercises-shapes

  point.h
  point.cpp

  circle.h
  circle.cpp

  square.h
  square.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-shapes

  PUBLIC
  .
)
