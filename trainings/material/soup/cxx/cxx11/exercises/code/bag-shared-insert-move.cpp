#include "bag-shared.h"

#include <gtest/gtest.h>

TEST(bag_shared_suite, insert_move)
{
    auto p = std::make_shared<BagShared::Item>("something", 42);

    BagShared bag;
    auto weakref = bag.insert(std::move(p));
    ASSERT_EQ(p, nullptr);

    {
        auto found = bag.find_by_int(42);
        ASSERT_EQ(found->first, "something");
        ASSERT_EQ(found->second, 42);
    }

    {
        auto sharedref = weakref.lock();
        ASSERT_NE(sharedref, nullptr);

        ASSERT_EQ(sharedref->first, "something");
        ASSERT_EQ(sharedref->second, 42);
    }

    // remove item again, and see how weak_ptr behaves
    {
        bag.remove_by_int(42);
        auto sharedref = weakref.lock();
        ASSERT_EQ(sharedref, nullptr);
    }
}
