ADD_EXECUTABLE(
  c++11-smartptr 

  intro-leak.cpp

  handwritten-smart-ptr-basic.cpp
  #handwritten-smart-ptr-copy-bad.cpp
  handwritten-smart-ptr-copy-autoptr-style.cpp
  handwritten-smart-ptr-explicit-move.cpp

  handwritten-smart-ptr-all.cpp


  unique-ptr-basic.cpp
  # unique-ptr-ownership-error.cpp
  unique-ptr-ownership-move.cpp
  unique-ptr-verbose-ctor.cpp
  unique-ptr-make-unique.cpp
  unique-ptr-implicit-ownership-transfer.cpp
  unique-ptr-release-reset.cpp

  unique-ptr-all.cpp


  shared-ptr-basic.cpp
  shared-ptr-basic-make_shared.cpp
  shared-ptr-cyclic.cpp
  shared-ptr-all.cpp
)

TARGET_LINK_LIBRARIES(c++11-smartptr gtest_main)
