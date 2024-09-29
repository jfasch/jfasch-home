#include "point.h"
#include <iostream>

int main()
{
    point p{2, 4};
    p.move(1, 2);
    std::cout << '(' << p.x() << ',' << p.y() << ")\n";
    return 0;
}
