ADD_LIBRARY(
  cxx-exercises-displays-core

  display-null.h
  display-null.cpp

  display-console.h
  display-console.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-displays-core

  PUBLIC
  .
)
