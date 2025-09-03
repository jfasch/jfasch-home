#ifndef POINT_H
#define POINT_H

#include <cmath>

class point
{
public:
    point() = default;  // since C++ 11
    point(int x, int y) : _x(x), _y(y) {}

    // access methods ("getters")
    int x() { return _x; }
    int y() { return _y; }

    void move(int x, int y)
    {
        _x += x;
        _y += y;
    }

    double distance(point other)
    {
        auto a = std::fabs(_x - other._x);
        auto b = std::fabs(_y - other._y);
        auto c = std::sqrt(std::pow(a, 2) + std::pow(b, 2));

        return c;
    }

    double distance_origin()
    {
        return distance(point{0,0});
    }

private:
    int _x{};  // since C++ 11
    int _y{};  // since C++ 11
};

#endif
