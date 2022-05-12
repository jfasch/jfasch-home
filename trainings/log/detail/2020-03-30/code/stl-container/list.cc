#include <gtest/gtest.h>

#include <list>
#include <algorithm>

using namespace std;


TEST(List, Append)
{
    list<int> l;

    l.push_back(42);
    l.push_back(7);
    l.push_back(666);

    ASSERT_EQ(l.size(), 3);
}

TEST(List, Initialize)
{
    const list<int> l{42, 7, 666};
    ASSERT_EQ(l.size(), 3);
}

TEST(List, Insert_Before_666)
{
    list<int> l{42, 7, 666};
    auto position = find(l.begin(), l.end(), 666);
    ASSERT_NE(position, l.end());
    ASSERT_EQ(*position, 666);

    l.insert(position, 400);
}

TEST(List, Erase_All_7)
{
    list<int> l{42, 7, 666, 7};
    
    auto pelem = l.begin();
    while (pelem != l.end()) {
        if (*pelem == 7)
            pelem = l.erase(pelem);
        else
            pelem++;
    }

    ASSERT_EQ(l.size(), 2);
}
