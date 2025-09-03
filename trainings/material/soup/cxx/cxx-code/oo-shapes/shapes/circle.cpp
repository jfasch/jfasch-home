#include "circle.h"

#if __cplusplus >= 202002L

#include <numbers>
static const double mypi = std::numbers::pi;

#else

#include <cmath>
static const double mypi = M_PI;

#endif

double Circle::area() const
{
    return _radius * _radius * mypi;
}
