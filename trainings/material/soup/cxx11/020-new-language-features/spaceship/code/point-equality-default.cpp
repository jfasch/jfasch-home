#include <cassert>

struct point
{
    int x, y;

    bool operator==(const point& rhs) const = default; // <-- cool!
};

struct compatible_point
{
    int x, y;

    operator point() const
    {
        return {x,y};
    }
};

int main()
{
    point p{1,2};
    compatible_point cp{1,2};

    assert(p == cp);                                   // <-- p.operator==(cp), ok
    assert(cp == p);                                   // <-- cp.operator==(p), does not exist
    
    return 0;
}
