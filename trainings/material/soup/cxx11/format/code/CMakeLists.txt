add_executable(
  c++11-format-suite

  tests.cpp
)
target_link_libraries(c++11-format-suite gtest_main)
add_test(NAME c++11-format-suite COMMAND c++11-format-suite)

add_executable(
  c++11-format-unicode

  unicode.cpp
)
