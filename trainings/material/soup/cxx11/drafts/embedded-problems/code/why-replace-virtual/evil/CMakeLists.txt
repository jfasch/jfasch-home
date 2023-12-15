ADD_LIBRARY(
  replace-virtual--evil

  sensors.h
  sensors.cpp
)

ADD_EXECUTABLE(
  replace-virtual--evil-main 
  main.cpp
)
TARGET_LINK_LIBRARIES(
  replace-virtual--evil-main
  replace-virtual--evil
)

ADD_EXECUTABLE(
  replace-virtual--evil-bench 
  bench.cpp
)
TARGET_LINK_LIBRARIES(
  replace-virtual--evil-bench
  replace-virtual--evil
  benchmark::benchmark_main
)
