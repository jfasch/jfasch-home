ADD_EXECUTABLE(
  cxx-exercises-switches-sysfs--suite

  switch-sysfs-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-switches-sysfs--suite

  cxx-exercises-switches-sysfs
  gtest_main 
)

add_test(NAME cxx-exercises-switches-sysfs--suite COMMAND cxx-exercises-switches-sysfs--suite)
