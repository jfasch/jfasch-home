ADD_EXECUTABLE(
  c++03-data-encapsulation-suite

  c-struct-initialization.cpp
  c-default-constructor-init.cpp
  c-default-constructor-create.cpp
  c-constructor.cpp
  c-eq-ne.cpp
  c-move.cpp
  c-add-sub.cpp
  c-abs.cpp
  c-distance.cpp

  cpp-default-constructor.cpp
  cpp-constructor-coordinates.cpp
  cpp-eq-ne.cpp
  cpp-move-op-pluseq.cpp
  cpp-move-func.cpp
  cpp-add-sub.cpp
  cpp-abs.cpp
  cpp-distance.cpp
  cpp-operator-ostream.cpp

  cpp-generated-copy.cpp
  cpp-manual-copy.cpp
)
TARGET_LINK_LIBRARIES(c++03-data-encapsulation-suite gtest_main)
add_test(NAME c++03-data-encapsulation-suite COMMAND c++03-data-encapsulation-suite)

ADD_EXECUTABLE(c++03-class c++03-class.cpp)
#TARGET_LINK_LIBRARIES(c++03-class m)

ADD_EXECUTABLE(c++03-default-ctor-compiler-generated c++03-default-ctor-compiler-generated.cpp)

ADD_EXECUTABLE(c++03-default-ctor-compiler-generated-pitfall c++03-default-ctor-compiler-generated-pitfall.cpp)
SET_SOURCE_FILES_PROPERTIES(c++03-default-ctor-compiler-generated-pitfall.cpp PROPERTIES COMPILE_FLAGS -Wno-uninitialized)

ADD_EXECUTABLE(c++03-copy-string-10 c++03-copy-string-10.cpp)
ADD_EXECUTABLE(c++03-copy-string-20-03 c++03-copy-string-20-03.cpp)
ADD_EXECUTABLE(c++03-copy-string-20-11 c++03-copy-string-20-11.cpp)

ADD_EXECUTABLE(c-point c-point.c)
