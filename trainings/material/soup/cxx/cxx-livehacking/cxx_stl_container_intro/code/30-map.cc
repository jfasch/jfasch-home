#include <gtest/gtest.h>

#include <map>
#include <string>


TEST(Map, InsertFind)
{
    std::map<int, std::string> m;
    m.insert(std::make_pair(666, "666"));
    m.insert(std::make_pair(42, "42"));

    auto found = m.find(666);
    ASSERT_NE(found, m.end());
    ASSERT_EQ(found->first, 666);
    ASSERT_EQ(found->second, "666");
}

TEST(Map, EraseByPosition)
{
    std::map<int, std::string> m{{666, "666"}, {42, "42"}}; // C++11

    // find element
    auto found = m.find(666);
    ASSERT_NE(found, m.end());

    // remove by position
    m.erase(found);

    ASSERT_EQ(m.find(666), m.end()); // verify not in map
}

TEST(Map, EraseByKey)
{
    std::map<int, std::string> m{{666, "666"}, {42, "42"}}; // C++11

    // find element
    auto found = m.find(666);
    ASSERT_NE(found, m.end());

    // remove by position
    m.erase(found);

    ASSERT_EQ(m.find(666), m.end()); // verify not in map
}
