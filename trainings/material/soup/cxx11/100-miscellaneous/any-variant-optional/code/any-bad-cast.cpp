#include <gtest/gtest.h>
#include <any>

TEST(any_suite, bad_cast)
{
    std::any a = 42;
    ASSERT_THROW(
        {
            std::any_cast<std::string>(a);
        },
        std::bad_any_cast
    );
}

