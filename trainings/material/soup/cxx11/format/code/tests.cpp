#include <format>
#include <gtest/gtest.h>

TEST(format_suite, basic)
{
    ASSERT_EQ(std::format("The answer is {}", 42), "The answer is 42");

    // same with more syntax, but omitting position and formatting parameters
    ASSERT_EQ(std::format("The answer is {:}", 42), "The answer is 42");
}

TEST(format_suite, positional)
{
    ASSERT_EQ(std::format("The answer is {0}, evil {1}, answer again {0}", 42, 666), "The answer is 42, evil 666, answer again 42");
}

TEST(format_suite, not_consuming_all_args_is_not_an_error)
{
    ASSERT_EQ(std::format("The answer is {}", 42, "and not 666"), "The answer is 42");
}

TEST(format_suite, escape_curly)
{
    ASSERT_EQ(std::format("{{"), "{");
    ASSERT_EQ(std::format("}}"), "}");
    ASSERT_EQ(std::format("{{}}"), "{}");
}

TEST(format_suite, c_style_escapes)
{
    ASSERT_EQ(std::format("\t\n\\"), "\t\n\\");
}



//  format:   fill-and-align ﻿(optional) sign ﻿(optional) #(optional) 0(optional) width ﻿(optional) precision ﻿(optional) L(optional) type ﻿(optional) 


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

TEST(format_suite, fill_and_align__explicit_datatype)
{
    char c = 'x'; // ascii 120

    // str left
    ASSERT_EQ(std::format("{:6}", c), "x     ");

    // interpret as int -> right
    ASSERT_EQ(std::format("{:6d}", c), "   120");
}

// sign: + for sign on both negative and positive, - for only negative
TEST(format_suite, sign)
{
    ASSERT_EQ(std::format("{:+6}", 42), "   +42");
    ASSERT_EQ(std::format("{:+6}", -42), "   -42");
    ASSERT_EQ(std::format("{:-6}", 42), "    42");
    ASSERT_EQ(std::format("{:-6}", -42), "   -42");
}

TEST(format_suite, hash_integral)
{
    ASSERT_EQ(std::format("{:#x}", 42), "0x2a");
    ASSERT_EQ(std::format("{:d}", 42), "42");
    ASSERT_EQ(std::format("{:#o}", 42), "052");
    ASSERT_EQ(std::format("{:#b}", 42), "0b101010");

    ASSERT_EQ(std::format("{:#6x}", 42), "  0x2a");
    ASSERT_EQ(std::format("{:6d}", 42), "    42");
    ASSERT_EQ(std::format("{:#6b}", 42), "0b101010"); // longer than 6
}



// // error: call to consteval function ‘std::basic_format_string<char, int>(format)’ is not a constant expression
// TEST(format_suite, format_string_must_be_constexpr)
// {
//     std::string format = "The answer is";
//     format += " {}";
//     ASSERT_EQ(std::format(format, 42), "The answer is 42");
// }

// std::print c++23
