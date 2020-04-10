#include "point.h"

#include <gtest/gtest.h>


TEST(CXX_Point_Suite, InitializationAndMembers)
{
    {
        Point<int> p(1,2);
        ASSERT_EQ(p, Point<int>(1,2));
    }
    {
        Point<double> p(1.1,2.2);
        ASSERT_EQ(p, Point<double>(1.1,2.2));
    }
}
