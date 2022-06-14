ADD_EXECUTABLE(
  c++11-exercises-suite

  bag-copy-insert-find-suite.cpp
  bag-copy-remove-suite.cpp
  bag-unique-suite.cpp

  bag-shared-basic-suite.cpp
  bag-shared-insert-const-ref.cpp
  bag-shared-insert-move.cpp

)
TARGET_LINK_LIBRARIES(c++11-exercises-suite gtest_main)
