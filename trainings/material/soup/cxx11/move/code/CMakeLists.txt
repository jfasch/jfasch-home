ADD_EXECUTABLE(
  c++11-string-move-suite

  string-10-suite.cpp
  # string-10-suite-bogus.cpp
  string-20-suite.cpp
  # string-20-suite-bogus.cpp
  string-30-suite.cpp

  # person-suite-bogus.cpp
  person-suite.cpp
)

TARGET_LINK_LIBRARIES(c++11-string-move-suite gtest_main)
add_test(NAME c++11-string-move-suite COMMAND c++11-string-move-suite)
