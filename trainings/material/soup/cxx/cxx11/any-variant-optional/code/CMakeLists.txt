add_executable(
  c++11-any-variant-optional-suite

  variant-default_ctor.cpp
  variant-converting_ctor.cpp
  variant-bad-access.cpp
  variant-visit.cpp
  variant-get-if.cpp

  variant-string-and-charp.cpp
  variant-no-default-ctor.cpp

  any-default-ctor.cpp
  any-init-access.cpp
  any-copy.cpp
  any-bad-cast.cpp
  any-has-value.cpp
  any-ptr-cast.cpp
  any-reference-cast.cpp
  any-string-and-charp.cpp
)
target_link_libraries(c++11-any-variant-optional-suite gtest_main)
add_test(NAME c++11-any-variant-optional-suite COMMAND c++11-any-variant-optional-suite)

add_executable(c++11-variant-mem-usage variant-mem-usage.cpp)
add_executable(c++11-variant-mem-usage-2-uint8 variant-mem-usage-2-uint8.cpp)

add_executable(any-more any-more.cpp)
