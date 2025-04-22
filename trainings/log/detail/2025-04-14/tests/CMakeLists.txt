add_executable(
  2025-04-14--suite 

  intro.cpp
)

target_link_libraries(
  2025-04-14--suite

  gtest_main 
)

add_test(NAME 2025-04-14--suite COMMAND 2025-04-14--suite)
