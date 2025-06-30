#include <format>
#include <gtest/gtest.h>

// like python, but statically deduced
TEST(format_suite, fill_and_align__datatype_deduced_from_parameter)
{
    // explicit fill/align
    ASSERT_EQ(std::format("{:x<6}", 42), "42xxxx");
    ASSERT_EQ(std::format("{:x<6}", "42"), "42xxxx");

    // omitting fill/align -> space with type specific align: numeric-right/str-left
    ASSERT_EQ(std::format("{:6}", 42), "    42");
    ASSERT_EQ(std::format("{:6}", "42"), "42    ");

    // centering
    ASSERT_EQ(std::format("{:x^6}", "42"), "xx42xx");
}
