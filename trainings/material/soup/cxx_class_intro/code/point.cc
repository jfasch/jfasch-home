#include "point.h"


Point& Point::move(Point addend)
{
    _x += addend._x;
    _y += addend._y;
    return *this;
}

