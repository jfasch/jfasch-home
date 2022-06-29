#include "point3d.h"

#include <cmath>

point3d& point3d::operator+=(const point3d& other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return *this;
}

point3d& point3d::operator-=(const point3d& other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return *this;
}

point3d point3d::operator+(const point3d& other) const
{
    int x = _x + other._x;
    int y = _y + other._y;
    int z = _z + other._z;
    return point3d{x,y,z};
}

point3d point3d::operator-(const point3d& other) const
{
    int x = _x - other._x;
    int y = _y - other._y;
    int z = _z - other._z;
    return point3d{x,y,z};
}

double point3d::abs() const
{
    int hyp = _x*_x + _y*_y + _z*_z;
    return sqrt(hyp);
}

std::ostream& operator<<(std::ostream& s, const point3d& r)
{
    s << '(' << r.x() << ',' << r.y() << ',' << r.z() << ')';
    return s;
}
