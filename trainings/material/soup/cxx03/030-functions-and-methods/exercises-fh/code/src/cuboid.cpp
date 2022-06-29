#include "cuboid.h"

bool cuboid::operator==(const cuboid& other) const
{
    return
        _front_bottom_left == other._front_bottom_left &&
        _width == other._width &&
        _height == other._height &&
        _length == other._length;
}

cuboid& cuboid::operator+=(const point3d& vec)
{
    _front_bottom_left += vec;
    return *this;
}

cuboid& cuboid::operator-=(const point3d& vec)
{
    _front_bottom_left -= vec;
    return *this;
}

cuboid cuboid::operator+(const point3d& vec) const
{
    cuboid moved{*this};
    moved += vec;
    return moved;
}

cuboid cuboid::operator-(const point3d& vec) const
{
    cuboid moved{*this};
    moved -= vec;
    return moved;
}

std::ostream& operator<<(std::ostream& s, const cuboid& c)
{
    s << "cuboid(" << c.front_bottom_left() << ",w=" << c.width() << ",h=" << c.height() << ",l=" << c.length() << ')';
    return s;
}
