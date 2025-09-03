#pragma once

class point
{
public:
    point() = default;
    point(int x, int y) : _x(x), _y(y) {}

    int x() const { return _x; }                       // <-- const
    int y() const { return _y; }                       // <-- const

private:
    int _x{};
    int _y{};
};
