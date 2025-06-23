ADD_EXECUTABLE(
  c++11-smartptr-suite

  intro-leak.cpp

  handwritten-smart-ptr-basic.cpp
  #handwritten-smart-ptr-copy-bad.cpp
  handwritten-smart-ptr-copy-autoptr-style.cpp
  handwritten-smart-ptr-explicit-move.cpp

  # this belongs to ../../060-move
  
  # move ctor
  handwritten-smart-ptr-return-from-function.cpp
  handwritten-smart-ptr-assignment.cpp
  

  shared-ptr-all.cpp

  weak-ptr-basic.cpp
)
TARGET_LINK_LIBRARIES(c++11-smartptr-suite gtest_main)
add_test(NAME c++11-smartptr-suite COMMAND c++11-smartptr-suite)

ADD_EXECUTABLE(weak-ptr-demo-thread weak-ptr-demo-thread.cpp)
TARGET_LINK_LIBRARIES(weak-ptr-demo-thread Threads::Threads)
