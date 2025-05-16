#pragma once

class point
{
public:
    constexpr point() = default;
    constexpr point(int x, int y) : _x{x}, _y{y} {}
    constexpr point(const point&) = default;
    int x() const { return _x; }
    int y() const { return _y; }
private:
    int _x, _y;
};
