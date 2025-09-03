#ifndef POINT_H
#define POINT_H

#include <ostream>

class point
{
public:
    point() = default;
    point(int x, int y) : _x{x}, _y{y} {}

    bool operator==(point other) const
    {
        return _x == other._x && _y == other._y;
    }

    bool operator!=(point other) const
    {
        return !operator==(other);
    }

    point operator+(point other) const;
    point& operator+=(point vec);

    int x() const { return _x; }
    int y() const { return _y; }

    point operator-() const
    {
        return point{-_x, -_y};
    }

private:
    int _x{};
    int _y{};
};

std::ostream& operator<<(std::ostream& s, point p);

#endif
