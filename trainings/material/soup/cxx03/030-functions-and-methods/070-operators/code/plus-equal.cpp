#include <gtest/gtest.h>

class point
{
public:
    point(int x, int y) : _x{x}, _y{y} {}

    int x() const { return _x; }
    int y() const { return _y; }

    point& operator+=(point rhs)          // <--- object method (non-const, obviously)
    {
        _x += rhs._x;
        _y += rhs._y;
    
        return *this;
    }

private:
    int _x;
    int _y;
};

TEST(operators_suite, point_plus_equal)
{
    point p{2, 3};
    point vec{1, 2};

    point result = p += vec;

    ASSERT_EQ(p.x(), 3);
    ASSERT_EQ(p.y(), 5);

    ASSERT_EQ(p.x(), result.x());
    ASSERT_EQ(p.y(), result.y());
}
