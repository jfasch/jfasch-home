#pragma once

#include "point.h"

class Square
{
public:
    Square(const Point& bottom_left, int side_length) : _bottom_left(bottom_left), _side_length(side_length) {}

    const Point& bottom_left() const { return _bottom_left; }
    int side_length() const { return _side_length; }

    double area();

private:
    Point _bottom_left;
    int _side_length;
};
