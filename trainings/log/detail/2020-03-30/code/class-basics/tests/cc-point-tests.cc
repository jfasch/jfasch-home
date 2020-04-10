#include "../point.h"

#include <gtest/gtest.h>


// a C++ ctor call.
TEST(CXX_Point_Suite, InitializationAndMembers)
{
    Point p(1,2);

    ASSERT_EQ(p, Point(1,2));
}

// move a point by another point (a "vector", so to say). 
TEST(CXX_Point_Suite, Move)
{
    Point p(1,2);
    Point vector(3,3);
    p.move(vector);
    ASSERT_EQ(p, Point(4,5) /* temporary object created */);
}

// motivation for the C++ assignment operator (it returns the
// assigned-to object)
TEST(CXX_Point_Suite, C_Analogy)
{
    int i = 7;
    int j = 42;
    int k = 666;

    i = k += j; // the expression "k+=j" has a value: k
    ASSERT_EQ(i, k);
}

// functional test for the += operator.
TEST(CXX_Point_Suite, MoveOperator)
{
    Point p(1,2);
    Point vector(3,3);
    p += vector;
    ASSERT_EQ(p, Point(4,5));

    // vector has not been modified, but has only been used to move
    // the point p.
    ASSERT_EQ(vector, Point(3,3));

    // equivalent but clumsy
    Point q(1,2);
    q += vector;
    ASSERT_EQ(q, Point(4,5));
}

// operator+=() has a value, just like we saw in the "motivation test"
// above.
TEST(CXX_Point_Suite, MoveOperator_C_Analogy)
{
    Point p(1,2);
    Point vector(3,3);
    Point result = p += vector;
    ASSERT_EQ(result, p);
}

// testing a nasty detail. operator+=() return a reference to
// thio. here is the argumentation why one generally chooses this
// signature:

//     const Point& operator+=(const Point& rhs);

// although we return a reference to this, nobody must modify this.
TEST(CXX_Point_Suite, MoveOperator_C_Analogy_BadAndUglyAndEvil)
{
    Point p(1,2);
    Point vector(3,3);
    Point result = p += vector;
    ASSERT_EQ(result, p);

    // here, we assign to the result. the user (this test) has had no
    // other choice than to copy the returned value, so this is safe:
    result = Point(666, 666);

    // p must not have been modified
    ASSERT_EQ(p, Point(4,5));
}

// motivation for operator+() signature/semantics: lhs and rhs must be
// left intact.
TEST(CXX_Point_Suite, Add_C_Analogy)
{
    int a = 1;
    int b = 2;
    int c = a + b;
    ASSERT_EQ(c, 3);
    ASSERT_EQ(a, 1);
    ASSERT_EQ(b, 2);
}

// but first, the add() method which does the same.
TEST(CXX_Point_Suite, Add)
{
    Point a(1,2);
    Point b(3,4);
    Point c = Point::add(a, b);

    ASSERT_EQ(a, Point(1,2));
    ASSERT_EQ(b, Point(3,4));
    ASSERT_EQ(c, Point(4,6));
}

// ... and then the operator.
TEST(CXX_Point_Suite, AddOperator)
{
    Point a(1,2);
    Point b(3,4);
    Point c = a + b;

    ASSERT_EQ(a, Point(1,2));
    ASSERT_EQ(b, Point(3,4));
    ASSERT_EQ(c, Point(4,6));
}

// last not least: the equality operator.
TEST(CXX_Point_Suite, EqualityOperator)
{
    Point a(1,2);
    Point b(3,4);
    Point c(1,2);

    ASSERT_EQ(a,a);
    ASSERT_EQ(b,b);
    ASSERT_EQ(a,c);

    ASSERT_NE(a,b);

    ASSERT_NE(Point(3,3), Point(3,666));
}
