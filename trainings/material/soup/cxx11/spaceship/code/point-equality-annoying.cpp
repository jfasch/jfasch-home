#include <cassert>

struct point
{
    int x, y;

    bool operator==(const point& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
    bool operator!=(const point& rhs) const { return !operator==(rhs); }
};

int main()
{
    point p1{1,2};
    point p2{3,4};

    assert(p1 == p1);
    assert(p1 != p2);

    return 0;
}
