#include <gtest/gtest.h>

class point
{
public:
    point(int x, int y) : _x{x}, _y{y} {}

    int x() const { return _x; }
    int y() const { return _y; }

    static point add(point lhs, point rhs)
    {
        int x = lhs.x() + rhs.x();
        int y = lhs.y() + rhs.y();
   
        return point{x, y};
    }

private:
    int _x;
    int _y;
};

TEST(static_suite, static_method)
{
    point p1{1,2};
    point p2{3,4};

    point sum = point::add(p1, p2);    // <--- note the scope!

    ASSERT_EQ(sum.x(), 4);
    ASSERT_EQ(sum.y(), 6);
}
