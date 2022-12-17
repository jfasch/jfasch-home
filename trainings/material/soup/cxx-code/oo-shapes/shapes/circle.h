#pragma once

#include "point.h"

class Circle
{
public:
    Circle(const Point& center, int radius) : _center(center), _radius(radius) {}

    const Point& center() const { return _center; }
    int radius() const { return _radius; }

    double area() const;

private:
    Point _center;
    int _radius;
};
