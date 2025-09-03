ADD_LIBRARY(
  cxx-exercises-design-patterns-interpreter-expressions

  expression.h
  expression.cpp

  expression-sensorvalue.h
  expression-sensorvalue.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-design-patterns-interpreter-expressions

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-interpreter-expressions

  cxx-exercises-sensors-core
)
