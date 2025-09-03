#include "point.h"
#include <iostream>

int main()
{
    point p{2, 4};
    std::cout << '(' << p.x() << ',' << p.y() << ")\n";
    return 0;
}
