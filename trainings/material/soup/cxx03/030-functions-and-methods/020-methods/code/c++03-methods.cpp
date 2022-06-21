#include "point.h"
#include <iostream>


int main()
{
    point p{2, 4};

    p.move(1, 0);
    double d_orig = p.distance_origin();
    std::cout << "distance of (" << p.x() << ',' << p.y() << ") from origin: "  << d_orig << std::endl;

    point other_p{4, 4};
    double d_other = p.distance(other_p);

    std::cout <<
        "distance of (" << p.x() << ',' << p.y() << ") "
        "from (" << other_p.x() << ',' << other_p.y() << "): "  << d_other << std::endl;

    return 0;
}
