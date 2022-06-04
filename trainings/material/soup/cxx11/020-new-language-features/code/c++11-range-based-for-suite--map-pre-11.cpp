#include <gtest/gtest.h>
#include <map>
#include <string>

static void do_something_with(int, const std::string&) { /*...*/ }

TEST(range_based_for_suite, map_pre_11)
{
    using table = std::map<int, std::string>;

    // no initialization in C++<11; have to insert at runtime
    table translations;
    translations.insert(std::make_pair(0, "zero"));
    translations.insert(std::make_pair(1, "one"));
    translations.insert(std::make_pair(2, "two"));

    // iteration using iterator objects (c/v pointer arithmetic)
    for (table::const_iterator it=translations.begin(); it!=translations.end(); ++it) {
        int num = it->first;
        std::string str = it->second;

        do_something_with(num, str);
    }
}
