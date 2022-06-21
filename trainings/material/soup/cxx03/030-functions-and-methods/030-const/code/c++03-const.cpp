#include "point.h"
#include <iostream>


int main()
{
    const point p{2, 4};   // <--- const

    double d_orig = p.distance_origin();
    std::cout << "distance of (" << p.x() << ',' << p.y() << ") from origin: "  << d_orig << std::endl;

    return 0;
}
