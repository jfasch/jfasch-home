#pragma once

#include <cmath>

class point
{
public:
    point() = default;
    point(int x, int y) : _x(x), _y(y) {}

    int x() const { return _x; }
    int y() const { return _y; }

    void move(int x, int y) { _x += x; _y += y; }
    void move(point vec)    { move(vec.x(), vec._y); } // <-- overload

    double distance(point other) const
    {
        return std::sqrt(
            std::pow(std::fabs(_x - other._x), 2) +
            std::pow(std::fabs(_y - other._y), 2)
        );
    }

    double distance() const
    {
        return distance(point(0,0));
    }

private:
    int _x{};
    int _y{};
};
