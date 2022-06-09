#include <cmath>
#include <iostream>

class point
{
public:
    point() : _x{0}, _y{0} {}
    point(int x, int y) : _x{x}, _y{y} {}

    int x() const { return _x; }
    int y() const { return _y; }

    point& operator+=(const point& p)
    {
        _x += p._x;
        _y += p._y;
        return *this;
    }

    point operator+(const point& rhs) const
    {
        return point{_x+rhs._x, _y+rhs._y};
    }

    double distance_from_origin() const
    {
        return sqrt(_x*_x + _y*_y);
    }

private:
    int _x;
    int _y;
};

int main(void)
{
    point A{1,2}, B{2,4};
    point C, D;

    C = A;

    double distance = A.distance_from_origin();
    std::cout << "|A|: " << distance << std::endl;

    D = A + B;
    std::cout << "D.x: " << D.x() << ", D.y: " << D.y() << std::endl;

    C += point(2,3);
    std::cout << "C.x: " << C.x() << ", C.y: " << C.y() << std::endl;

    return 0;
}
