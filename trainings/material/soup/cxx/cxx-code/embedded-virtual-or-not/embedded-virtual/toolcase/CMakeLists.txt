add_library(
  embedded-virtual-toolcase

  loop.h

  sink.h
  sink-copyable.h
  sink-copyable.cpp
  sink-movable.h
  sink-movable.cpp

  source.h
  source-copyable.h
  source-copyable.cpp
  source-movable.h
  source-movable.cpp
)

target_include_directories(
  embedded-virtual-toolcase

  INTERFACE

  .
)
