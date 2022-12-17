#include "circle.h"

#include <numbers>

double Circle::area() const
{
    return _radius * _radius * std::numbers::pi;
}
