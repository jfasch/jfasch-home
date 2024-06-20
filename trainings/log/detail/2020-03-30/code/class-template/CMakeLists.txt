ADD_EXECUTABLE(gm-class-templates tests.cc)
TARGET_LINK_LIBRARIES(gm-class-templates gtest_main)

add_test(NAME gm-class-templates COMMAND gm-class-templates)
