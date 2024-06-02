#include <gtest/gtest.h>
#include <any>

TEST(any_suite, char_ptr_careful)
{
    std::any a = "howdy";                              // <-- careful: const char*, not std::string!
    ASSERT_EQ(a.type(), typeid(const char*));

    const char* s = std::any_cast<const char*>(a);
    ASSERT_EQ(s, "howdy");                             // <--- this is not obvious!
    char* cmp = new char[]{"howdy"};
    ASSERT_NE(s, cmp);
    delete[] cmp;
}

