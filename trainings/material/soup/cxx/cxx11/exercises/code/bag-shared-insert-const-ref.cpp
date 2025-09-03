#include "bag-shared.h"

#include <gtest/gtest.h>

TEST(bag_shared_suite, insert_const_ref)
{
    auto p = std::make_shared<BagShared::Item>("something", 42);

    BagShared bag;
    bag.insert(p);

    p->second = 43;
    auto found = bag.find_by_int(43);
    ASSERT_NE(found, nullptr);
}
