ADD_EXECUTABLE(
  c++11-any-variant-optional-suite

  variant.cpp
  any.cpp
)
TARGET_LINK_LIBRARIES(c++11-any-variant-optional-suite gtest_main)

ADD_EXECUTABLE(visit-variant visit-variant.cpp)
ADD_EXECUTABLE(any-more any-more.cpp)
