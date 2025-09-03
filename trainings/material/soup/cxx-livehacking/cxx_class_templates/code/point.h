#ifndef __HAVE_POINT_H__
#define __HAVE_POINT_H__


template<typename T> class Point
{
public:
    Point(T x, T y) : _x(x), _y(y) {}

    T x() const { return _x; }
    T y() const { return _y; }

    Point& move(Point addend)
    {
        _x += addend._x;
        _y += addend._y;
        return *this;
    }
    Point& operator+=(Point addend) { return move(addend); }

    bool operator==(Point rhs) const { return _x == rhs._x && _y == rhs._y; }
    bool operator!=(Point rhs) const { return !(*this == rhs); }
    Point operator+(Point rhs) const { return Point(_x + rhs._x, _y + rhs._y); }

private:
    T _x;
    T _y;
};

#endif
