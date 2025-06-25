add_executable(
  c++11-weak-ptr-suite

  basic.cpp
)
target_link_libraries(c++11-weak-ptr-suite gtest_main)
add_test(NAME c++11-weak-ptr-suite COMMAND c++11-weak-ptr-suite)

add_executable(c++11-weak-ptr-demo-thread demo-thread.cpp)
