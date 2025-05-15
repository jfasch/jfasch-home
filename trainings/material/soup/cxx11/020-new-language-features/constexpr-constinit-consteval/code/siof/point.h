#pragma once

class point
{
public:
    point(int x, int y) : _x{x}, _y{y} {}
    int x() const { return _x; }
    int y() const { return _y; }
private:
    int _x, _y;
};
