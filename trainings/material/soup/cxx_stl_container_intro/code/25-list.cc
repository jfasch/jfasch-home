#include <gtest/gtest.h>

#include <list>
#include <algorithm>


TEST(List, Append)
{
    std::list<int> l;
    l.push_back(42);
    l.push_back(7);
    l.push_back(666);

    ASSERT_EQ(l.size(), 3);
}

TEST(List, Insert)
{
    std::list<int> l{42, 7, 666}; // C++11

    // insert 667 before 666 ...

    // find position where to insert
    auto position = std::find(l.begin(), l.end(), 666);
    ASSERT_NE(position, l.end());

    // insert at (i.e. before) position
    auto inserted = l.insert(position, 667);
    ASSERT_NE(inserted, l.end());
    ASSERT_EQ(l.size(), 4);
}

TEST(List, Erase)
{
    std::list<int> l;
    l.push_back(42);
    l.push_back(7);
    l.push_back(666);
    l.push_back(7);

    // erase elements with value 7

#if 0 // naive variant; ask valgrind
    for (auto it=l.begin(); it!=l.end(); it++) {
        if (*it == 7)
            l.erase(it);
    }
#endif

    auto it = l.begin();
    while (it != l.end()) {
        if (*it == 7)
            it = l.erase(it);
        else
            it++;
    }

    ASSERT_EQ(l.size(), 2);
}
