#include "bag-copy.h"

#include <gtest/gtest.h>


TEST(bag_copy_suite, find_by_int_ok)
{
    BagCopy bag;
    bag.insert(BagCopy::Item("something", 42));
    bag.insert(BagCopy::Item("anything", 666));

    auto item = bag.find_by_int(42);
    ASSERT_EQ(item.first, "something");
    ASSERT_EQ(item.second, 42);
}

TEST(bag_copy_suite, find_by_int_nok)
{
    BagCopy bag;
    bag.insert(BagCopy::Item("something", 42));
    bag.insert(BagCopy::Item("anything", 666));

    BagCopy::Item item = bag.find_by_int(7);
    ASSERT_EQ(item.first, "");
    ASSERT_EQ(item.second, 0);
}
