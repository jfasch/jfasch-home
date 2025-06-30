add_executable(
  c++11-format-suite

  basics.cpp
  positional.cpp
  not_consuming_all_args_is_not_an_error.cpp
  escape_curly.cpp
  c_style_escapes.cpp
  fill_and_align__datatype_deduced_from_parameter.cpp
  fill_and_align__explicit_datatype.cpp
  sign.cpp
  hash_integral.cpp
)
target_link_libraries(c++11-format-suite gtest_main)
add_test(NAME c++11-format-suite COMMAND c++11-format-suite)
