#include <gtest/gtest.h>

class point
{
public:
    point(int x, int y) : _x{x}, _y{y} {}

    int x() const { return _x; }
    int y() const { return _y; }

    bool operator==(point rhs) const     // <--- object method (const!)
    {
        return
            _x == rhs._x &&              // <--- direct member access possible
            _y == rhs._y;                // <--- direct member access possible
    }

    bool operator!=(point rhs) const     // <--- object method (const!)
    {
        return !operator==(rhs);         // <--- again, defined in terms of "=="
    }

private:
    int _x;
    int _y;
};

TEST(operators_suite, equals_object)
{
    point p1{2, 3};
    point p2{3, 4};

    ASSERT_NE(p1, p2);
    ASSERT_EQ(p1, p1);

    // operators are ordinary methods:
    ASSERT_EQ(p1.operator==(p2), false);
    ASSERT_EQ(p1.operator!=(p2), true);
}
