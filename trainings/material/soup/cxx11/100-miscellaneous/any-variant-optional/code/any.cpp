#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wrestrict"  // no idea, happens with -O3

#include <gtest/gtest.h>
#include <any>
#include <string>
#include <vector>


TEST(any_suite, basic)
{
    std::any a = 42;
    ASSERT_EQ(a.type(), typeid(int));
    int i = std::any_cast<int>(a);
    ASSERT_EQ(i, 42);

    a = std::string("howdy");
    ASSERT_EQ(a.type(), typeid(std::string));
    std::string s = std::any_cast<std::string>(a);
    ASSERT_EQ(s, "howdy");
}

TEST(any_suite, char_ptr_careful)
{
    std::any a = "howdy";   // <-- careful: const char*, not std::string!
    ASSERT_EQ(a.type(), typeid(const char*));
    const char* s = std::any_cast<const char*>(a);
    ASSERT_EQ(s, "howdy");
    char* cmp = new char[]{"howdy"};
    ASSERT_NE(s, cmp);
    delete[] cmp;
}

TEST(any_suite, copy)
{
    std::any a1 = std::string("howdy");
    std::any a2 = a1;        // <--- copy ctor
    ASSERT_EQ(std::any_cast<std::string>(a2), "howdy");

    std::any a3 = std::vector<int>{1, 2, 3, 4, 5, 6};
    a3 = a2;                 // <--- assignment; frees a3's current content of course
    ASSERT_EQ(std::any_cast<std::string>(a3), "howdy");
}

TEST(any_suite, bad_cast)
{
    std::any a = 42;
    ASSERT_THROW(
        {
            auto s = std::any_cast<std::string>(a);
        },
        std::bad_any_cast
    );
}

TEST(any_suite, has_value)
{
    std::any a = 42;
    bool is_something_in_it = a.has_value();
    ASSERT_TRUE(is_something_in_it);

    a.reset();
    ASSERT_FALSE(a.has_value());
}

TEST(any_suite, reference_cast)
{
    std::any a = std::string("howdy");
    std::string& s = std::any_cast<std::string&>(a);

    s = "moin";      // <--- modify a
    ASSERT_EQ(std::any_cast<const std::string&>(a), "moin");
}

TEST(any_suite, pointer_cast_avoid_exception)
{
    std::any a = 42;
    if (const std::string* sp = std::any_cast<const std::string>(&a)) {
        FAIL();      // <--- never reached because cast does not throw
        (void)sp;
    }
    auto ip = std::any_cast<int>(&a);
    ASSERT_EQ(*ip, 42);
}

#pragma GCC diagnostic pop
