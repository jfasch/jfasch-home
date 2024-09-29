#include "point.h"
#include <iostream>

int main()
{
    const point p{2, 4};
    std::cout << '(' << p.x() << ',' << p.y() << ")\n";
    return 0;
}
