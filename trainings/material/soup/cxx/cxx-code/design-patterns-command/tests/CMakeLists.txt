ADD_EXECUTABLE(
  cxx-exercises-design-patterns-command--suite

  command-suite-insert.cpp
  command-suite-insert-by-base.cpp
  command-suite-find.cpp
  command-suite-drop.cpp
  command-suite-notfound.cpp
  command-suite-notinserted.cpp
  command-suite-bulk-insert.cpp
  command-suite-bulk-insert--std_initializer_list.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-command--suite

  cxx-exercises-design-patterns-command-commands
  gtest_main 
)

add_test(NAME cxx-exercises-design-patterns-command--suite COMMAND cxx-exercises-design-patterns-command--suite)




