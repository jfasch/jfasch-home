ADD_LIBRARY(
  replace-virtual

  avg.h
  sensors.h
  sensors.cpp
)

ADD_EXECUTABLE(
  replace-virtual--bench 
  bench.cpp
)
TARGET_LINK_LIBRARIES(
  replace-virtual--bench

  replace-virtual
  benchmark::benchmark_main
)
