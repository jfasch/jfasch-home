#include "../c-point.h"

#include <gtest/gtest.h>


// C structs are initialized using "struct initialization"
TEST(C_Point_Suite, InitializationAndMembers)
{
    struct point p = {1,2}; // <- here
    ASSERT_EQ(p.x, 1);
    ASSERT_EQ(p.y, 2);
}

// in C, you associate free-flowing functions with the datatype they
// operate on. the association is only convention though, not syntax.

// here: the move() "method". it moves the first parameter ("this" in
// C++) in place, this is why it is passed by pointer.
TEST(C_Point_Suite, Move)
{
    struct point p = {1,2};
    struct point vector = {3,3};

    point_move(&p, &vector);

    ASSERT_EQ(p.x, 4);
    ASSERT_EQ(p.y, 5);
}

// the add() "method". it takes two points read-only, and makes a
// third of it.
TEST(C_Point_Suite, Add)
{
    struct point p1 = {1,2};
    struct point vector = {3,3};

    struct point p2 = point_add(&p1, &vector);

    ASSERT_EQ(p1.x, 1);
    ASSERT_EQ(p1.y, 2);
    
    ASSERT_EQ(p2.x, 4);
    ASSERT_EQ(p2.y, 5);
}
