ADD_EXECUTABLE(c++-class-templates tests.cc)
TARGET_LINK_LIBRARIES(c++-class-templates gtest_main)
add_test(NAME c++-class-templates COMMAND c++-class-templates)
