ADD_EXECUTABLE(
  c++11-brace-initialization-suite

  # narrowing.cpp

  explicit-ctor.cpp
  ambiguity.cpp
)
TARGET_LINK_LIBRARIES(c++11-brace-initialization-suite gtest_main)
add_test(NAME c++11-brace-initialization-suite COMMAND c++11-brace-initialization-suite)

ADD_EXECUTABLE(c++11-brace-initialization-vector-explicit c++11-brace-initialization-vector-explicit.cpp)
ADD_EXECUTABLE(c++11-brace-initialization-vector-initializer-list c++11-brace-initialization-vector-initializer-list.cpp)
