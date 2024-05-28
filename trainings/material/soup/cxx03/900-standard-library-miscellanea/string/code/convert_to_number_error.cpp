#include <gtest/gtest.h>
#include <string>

TEST(string_suite, convert_to_number_error)
{
    try {
        std::stoi("not-a-valid-number");
        FAIL();                                        // <--- not reached because stoi throws
    }
    catch (const std::invalid_argument&) {}
}

