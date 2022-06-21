#ifndef POINT_H
#define POINT_H

#include <cmath>

class point
{
public:
    point() = default;  // since C++ 11
    point(int x, int y) : _x(x), _y(y) {}

    // access methods ("getters")
    int x() const /* <--- */ { return _x; }
    int y() const /* <--- */ { return _y; }

    void move(int x, int y)    // modifies object, hence non-const
    {
        _x += x;
        _y += y;
    }

    double distance(point other) const   // <---
    {
        auto a = std::fabs(_x - other._x);
        auto b = std::fabs(_y - other._y);
        auto c = std::sqrt(std::pow(a, 2) + std::pow(b, 2));

        return c;
    }

    double distance_origin() const       // <---
    {
        return distance(point{0,0});
    }

private:
    int _x{};  // initialization, since C++ 11
    int _y{};  // initialization, since C++ 11
};

#endif
