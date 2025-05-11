#include <cassert>

struct point
{
    int x, y;
    bool operator==(const point& rhs) const = default;
};

struct compatible_point
{
    int x, y;
    operator point() const { return point{x,y}; }
};

int main()
{
    point p{1,2};
    compatible_point cp{1,2};

    assert(p == cp);                                   // <-- rhs converted to point, old-style
    assert(cp == p);                                   // <-- magic: lhs and rhs reversed

    return 0;
}
