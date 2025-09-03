#include <iostream>

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

static std::ostream& operator<<(std::ostream& s, point p) // <--- "static inline" is another story
{
    s << '(' << p.x() << ',' << p.y() << ')';
    return s;
}


int main()
{
    point p1{1,2};
    point p2{3,4};

    std::cout << "p1: " << p1 << ", p2: " << p2 << std::endl;

    return 0;
}
