#include <gtest/gtest.h>
#include <string>

TEST(string_suite, comparison)
{
    std::string aaron = "Aaron";
    std::string adam = "Adam";

    // "Aaron" compares less-than "Adam", lexicographically
    if (aaron < adam) {
        // yes
    }
    else {
        FAIL(); // not reached because aaron < adam
    }
}
