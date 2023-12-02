ADD_EXECUTABLE(
  c++11-any-variant-optional-suite

  variant-default_ctor.cpp
  variant-converting_ctor.cpp
  variant-bad-access.cpp
  variant-visit.cpp
  variant-get-if.cpp

  variant-string-and-charp.cpp
  variant-no-default-ctor.cpp

  any.cpp
)
TARGET_LINK_LIBRARIES(c++11-any-variant-optional-suite gtest_main)

ADD_EXECUTABLE(any-more any-more.cpp)
