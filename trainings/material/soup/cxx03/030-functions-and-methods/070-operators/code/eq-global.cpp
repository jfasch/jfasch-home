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

bool operator==(point lhs, point rhs)    // <--- global function (not inside class definition)
{
    return
        lhs.x() == rhs.x() &&            // <--- using public access methods
        lhs.y() == rhs.y();              // <--- using public access methods
}

bool operator!=(point lhs, point rhs)    // <--- global function (not inside class definition)
{
    return !operator==(lhs, rhs);        // <--- defined in terms of "=="
}

TEST(operators_suite, equals_global)
{
    point p1{2, 3};
    point p2{3, 4};

    ASSERT_NE(p1, p2);
    ASSERT_EQ(p1, p1);

    // operators are ordinary functions:
    ASSERT_EQ(operator==(p1, p2), false);
    ASSERT_EQ(operator!=(p1, p2), true);
}
