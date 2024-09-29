#pragma once

class point
{
public:
    point() = default;
    point(int x, int y) : _x(x), _y(y) {}

    int x() const { return _x; }
    int y() const { return _y; }

    void move(int x, int y) { _x += x; _y += y; }
    void move(point vec)    { move(vec.x(), vec._y); } // <-- overload

private:
    int _x{};
    int _y{};
};
