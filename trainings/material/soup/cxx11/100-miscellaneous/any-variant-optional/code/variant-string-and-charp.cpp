#include <gtest/gtest.h>
#include <string>
#include <variant>

TEST(variant_suite, string_charp)
{
    std::variant<std::string, const char*> v;
    ASSERT_EQ(std::get<std::string>(v), std::string());

    const char* s = "blah";
    v = s;
    ASSERT_EQ(std::get<const char*>(v), s);

    v = "blah";
    ASSERT_EQ(std::get_if<std::string>(&v), nullptr);
}
