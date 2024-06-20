ADD_EXECUTABLE(
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
TARGET_LINK_LIBRARIES(c++11-any-variant-optional-suite gtest_main)
add_test(NAME c++11-any-variant-optional-suite COMMAND c++11-any-variant-optional-suite)

ADD_EXECUTABLE(any-more any-more.cpp)
