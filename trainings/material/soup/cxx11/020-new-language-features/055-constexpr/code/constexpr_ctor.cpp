#include <gtest/gtest.h>


// constexpr ctor

#include <cmath>

class point
{
public:
    constexpr point(int x, int y) : _x(x), _y(y) {}
    constexpr double abs() const
    {
        return std::sqrt(_x*_x + _y*_y);
    }
private:
    int _x;
    int _y;
};

TEST(constexpr_suite, constexpr_ctor)
{
    constexpr point p(3,4);
    ASSERT_FLOAT_EQ(p.abs(), 5);
}
