#include "point.h"
#include <iostream>

int main()
{
    point p{2, 4};
    point vec{1, 2};
    p.move(vec);
    std::cout << '(' << p.x() << ',' << p.y() << ")\n";
    return 0;
}
