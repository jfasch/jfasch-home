#include "point.h"


point point::operator+(point other) const
{
    int x = _x + other._x;
    int y = _y + other._y;

    return point{x,y};
}

point& point::operator+=(point vec)
{
    _x += vec._x;
    _y += vec._y;

    return *this;
}

std::ostream& operator<<(std::ostream& s, point p)
{
    s << '(' << p.x() << ',' << p.y() << ')';
    return s;
}
