#include <gtest/gtest.h>

class point
{
public:
    point(int x, int y) : _x{x}, _y{y} {}

    int x() const { return _x; }
    int y() const { return _y; }

    point operator+(point rhs) const     // <--- object method (const!)
    {
        int x = _x + rhs._x;             // <--- direct member access possible
        int y = _y + rhs._y;             // <--- direct member access possible
    
        return point{x, y};
    }

private:
    int _x;
    int _y;
};

TEST(operators_suite, vector_addition_object)
{
    point p1{2, 3};
    point p2{3, 4};

    point sum = p1 + p2;

    ASSERT_EQ(sum.x(), 5);
    ASSERT_EQ(sum.y(), 7);
}
