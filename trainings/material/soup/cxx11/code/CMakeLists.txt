ADD_EXECUTABLE(
  c++11-new-language-features-suite

  initializer-list.cpp
)
TARGET_LINK_LIBRARIES(c++11-new-language-features-suite gtest_main)
add_test(NAME c++11-new-language-features-suite COMMAND c++11-new-language-features-suite)
