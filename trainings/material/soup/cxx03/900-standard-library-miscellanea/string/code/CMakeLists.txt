ADD_EXECUTABLE(
  c++03-string-suite

  initialization.cpp
  addition.cpp
  convert_to_signed_integer.cpp
  convert_to_unsigned_integer.cpp
  convert_from_something.cpp
  find.cpp
  substr.cpp
  )

TARGET_LINK_LIBRARIES(
  c++03-string-suite

  gtest_main 
  )
