ADD_EXECUTABLE(
  crtp-benches

  classic-virtual-bench.cpp
  unrelated-bench.cpp
)
TARGET_LINK_LIBRARIES(crtp-benches benchmark_main)
