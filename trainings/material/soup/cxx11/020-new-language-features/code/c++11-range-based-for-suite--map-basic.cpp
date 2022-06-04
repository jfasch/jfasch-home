#include <gtest/gtest.h>
#include <map>
#include <string>

static void do_something_with(int, const std::string&) { /*...*/ }

TEST(range_based_for_suite, map_basic)
{
    using table = std::map<int, std::string>;

    table translations {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
    };

    for (auto elem: translations) {
        auto num = elem.first;
        auto str = elem.second;

        do_something_with(num, str);
    }
}
