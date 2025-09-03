#include "point.h"
#include <iostream>

int main()
{
    const point p{2, 4};                               // <-- not altered
    std::cout << "distance from origin: " << p.distance() << '\n';
    std::cout << "distance from (1,2): "
              << p.distance(point(1,2))                // <-- nameless *temporary* object
              << '\n';
    return 0;
}
