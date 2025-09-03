ADD_LIBRARY(
  replace-virtual--naive

  sensors.h
  sensors.cpp
)

ADD_EXECUTABLE(
  replace-virtual--naive-main 
  main.cpp
)
TARGET_LINK_LIBRARIES(
  replace-virtual--naive-main
  replace-virtual--naive
)

ADD_EXECUTABLE(
  replace-virtual--naive-bench 
  bench.cpp
)
TARGET_LINK_LIBRARIES(
  replace-virtual--naive-bench
  replace-virtual--naive
  benchmark::benchmark_main
)
