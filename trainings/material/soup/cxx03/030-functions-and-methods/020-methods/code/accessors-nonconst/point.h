#pragma once

class point
{
public:
    point() = default;                                 // <-- generates default ctor ...
    point(int x, int y) : _x(x), _y(y) {}

    int x() { return _x; }                             // <-- WRONG!
    int y() { return _y; }                             // <-- WRONG!

private:
    int _x{};                                          // <-- ... with these default values
    int _y{};                                          // <-- ...
};
