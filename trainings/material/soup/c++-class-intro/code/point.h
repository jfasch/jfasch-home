#ifndef __HAVE_POINT_H__
#define __HAVE_POINT_H__

class Point
{
public:
    Point(int x, int y) : _x(x), _y(y) {}

    int x() const { return _x; }
    int y() const { return _y; }

    Point& move(Point);
    Point& operator+=(Point addend) { return move(addend); }

    bool operator==(Point rhs) const { return _x == rhs._x && _y == rhs._y; }
    bool operator!=(Point rhs) const { return !(*this == rhs); }
    Point operator+(Point rhs) const { return Point(_x + rhs._x, _y + rhs._y); }

private:
    int _x;
    int _y;
};

#endif
