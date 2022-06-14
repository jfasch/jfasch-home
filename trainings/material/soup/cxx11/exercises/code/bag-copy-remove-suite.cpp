#include "bag-copy.h"

#include <gtest/gtest.h>


TEST(bag_copy_suite, remove_by_int_ok)
{
    BagCopy bag;
    bag.insert(BagCopy::Item("something", 42));
    bag.insert(BagCopy::Item("anything", 666));

    std::size_t nremoved = bag.remove_by_int(42);
    ASSERT_EQ(nremoved, 1);
}

