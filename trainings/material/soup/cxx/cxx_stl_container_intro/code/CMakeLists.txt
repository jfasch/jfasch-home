ADD_EXECUTABLE(c++-stl-container-intro

  10-pointer-arith-basics.cc
  11-pointer-arith-ranges.cc
  20-vector.cc
  25-vector-naive-copy.cc
  26-vector-algo-copy.cc
  25-list.cc
  30-map.cc
)
TARGET_LINK_LIBRARIES(c++-stl-container-intro gtest_main)
