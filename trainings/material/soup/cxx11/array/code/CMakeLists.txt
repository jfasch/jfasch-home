add_executable(
  c++11-array-suite

  basic.cpp
  initialization.cpp
  deducing_type.cpp
  copy.cpp
  equality.cpp
  constexpr_equality.cpp
  range_for.cpp
  structured_binding.cpp
  sort.cpp
)
target_link_libraries(c++11-array-suite gtest_main)
add_test(NAME c++11-array-suite COMMAND c++11-array-suite)
