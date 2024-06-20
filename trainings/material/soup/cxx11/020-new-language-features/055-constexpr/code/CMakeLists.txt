ADD_EXECUTABLE(
  c++11-constexpr-suite

  basic.cpp
  basic_const_is_constexpr.cpp
  constexpr_function_requested.cpp
  constexpr_function_not_requested.cpp
  constexpr_recursive_function.cpp
  constexpr_ctor.cpp
)

TARGET_LINK_LIBRARIES(c++11-constexpr-suite gtest_main)
add_test(NAME c++11-constexpr-suite COMMAND c++11-constexpr-suite)
