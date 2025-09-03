#include "point.h"

void Point::move(const Point& vector)
{
    _x += vector._x;
    _y += vector._y;
}

Point& Point::operator+=(const Point& vector)
{
    move(vector);
    return *this;
}

Point Point::add(const Point& lhs, const Point& rhs)
{
    return Point(lhs._x+rhs._x, lhs._y+rhs._y);
}

Point Point::operator+(const Point& rhs) const
{
    return add(*this, rhs);
}

bool Point::equal(const Point& lhs, const Point& rhs)
{
    return lhs._x == rhs._x && lhs._y == rhs._y;
}

bool Point::operator==(const Point& rhs) const
{
    return equal(*this, rhs);
}
