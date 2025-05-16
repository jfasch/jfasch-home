add_executable(
  c++11-range-for-suite

  c++11-range-based-for-suite--map-pre-11.cpp
  c++11-range-based-for-suite--map-basic.cpp
  c++11-range-based-for-suite--map-basic-const-auto-reference.cpp
  c++11-range-based-for-suite--map-unpack-copy.cpp
  c++11-range-based-for-suite--map-unpack-reference.cpp
  c++11-range-based-for-suite--map-unpack-const-reference.cpp
)
target_link_libraries(c++11-range-for-suite gtest_main)
add_test(NAME c++11-range-for-suite COMMAND c++11-range-for-suite)
