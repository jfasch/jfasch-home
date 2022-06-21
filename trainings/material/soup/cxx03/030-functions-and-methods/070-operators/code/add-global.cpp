#include <gtest/gtest.h>

class point
{
public:
    point(int x, int y) : _x{x}, _y{y} {}

    int x() const { return _x; }
    int y() const { return _y; }

private:
    int _x;
    int _y;
};

point operator+(point lhs, point rhs)    // <--- global function (not inside class definition)
{
    int x = lhs.x() + rhs.x();           // <--- using public access methods
    int y = lhs.y() + rhs.y();           // <--- using public access methods
    
    return point{x, y};
}

TEST(operators_suite, vector_addition_global)
{
    point p1{2, 3};
    point p2{3, 4};

    point sum = p1 + p2;

    ASSERT_EQ(sum.x(), 5);
    ASSERT_EQ(sum.y(), 7);
}
