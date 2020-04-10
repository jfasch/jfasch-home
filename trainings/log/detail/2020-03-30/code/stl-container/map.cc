#include <gtest/gtest.h>

#include <map>
#include <string>
using namespace std;


TEST(Map, Initialization)
{
    map<int, string> m;
    m.insert(std::pair<int, string>(1, "eins"));
    m.insert(std::make_pair(666, "sechshundertsechsundsechzig"));
    m.insert(std::make_pair(43, "zweiundvierzig"));

    ASSERT_EQ(m.size(), 3);
}

TEST(Map, Initialization_CXX11)
{
    const map<int, string> m{{1, "eins"}, {666, "sechshundertsechsundsechzig"}, {43, "zweiundvierzig"}};
    ASSERT_EQ(m.size(), 3);
}

TEST(Map, Find)
{
    const map<int, string> m{{1, "eins"}, {666, "sechshundertsechsundsechzig"}, {43, "zweiundvierzig"}};

    auto found = m.find(666);
    ASSERT_NE(found, m.end());
    ASSERT_EQ(found->first, 666);
    ASSERT_EQ(found->second, "sechshundertsechsundsechzig");
}

TEST(Map, Erase)
{
    map<int, string> m{{1, "eins"}, {666, "sechshundertsechsundsechzig"}, {43, "zweiundvierzig"}};

    auto found = m.find(666);
    ASSERT_NE(found, m.end());

    m.erase(found);

    ASSERT_EQ(m.size(), 2);
}
