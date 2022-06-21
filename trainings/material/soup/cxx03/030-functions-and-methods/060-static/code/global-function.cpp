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

point add_points(point lhs, point rhs)
{
    int x = lhs.x() + rhs.x();
    int y = lhs.y() + rhs.y();
   
    return point{x, y};
}

TEST(static_suite, global_function)
{
    point p1{1,2};
    point p2{3,4};

    point sum = add_points(p1, p2);

    ASSERT_EQ(sum.x(), 4);
    ASSERT_EQ(sum.y(), 6);
}
