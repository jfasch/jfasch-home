ADD_EXECUTABLE(
  c++03-references-suite

  pass-by-copy.cpp
  pass-by-pointer.cpp
  pass-by-reference.cpp

#  pass-by-const-pointer.cpp
#  pass-by-const-reference.cpp

  pass-by-copy-expensive.cpp
  pass-by-const-reference-cheap.cpp
)
TARGET_LINK_LIBRARIES(c++03-references-suite gtest_main)

