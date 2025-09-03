#include "point.h"
#include <iostream>

int main()
{
    const point p{2, 4};                               // <-- move?
    const point vec{1, 2};
    p.move(vec);
    std::cout << '(' << p.x() << ',' << p.y() << ")\n";
    return 0;
}
