#ifndef POINT_H
#define POINT_H

#include <ostream>
#include <cmath>

class point
{
public:
    point() = default;
    point(int x, int y) : _x{x}, _y{y} {}

    int x() const { return _x; }
    int y() const { return _y; }

    bool operator==(point other) const { return _x == other._x && _y == other._y; }
    bool operator!=(point other) const { return !operator==(other); }

    point& operator+=(point vec)
    {
        _x += vec._x;
        _y += vec._y; 
        return *this;
    }

    point operator+(point other) const { return point(_x+other._x, _y+other._y); }
    point operator-(point other) const { return point(_x-other._x, _y-other._y); }

    double abs() const
    {
        int hyp = _x*_x + _y*_y;
        return sqrt(hyp);
    }

    double distance(point other) const
    {
        point diff = *this - other;
        return diff.abs();
    }

    void move(int x, int y)
    {
        _x += x;
        _y += y;
    }

private:
    int _x{};
    int _y{};
};

static inline std::ostream& operator<<(std::ostream& s, point p)
{
    s << '(' << p.x() << ',' << p.y() << ')';
    return s;
}

#endif
