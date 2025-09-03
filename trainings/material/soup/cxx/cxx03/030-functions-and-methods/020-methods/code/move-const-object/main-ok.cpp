#include "point.h"
#include <iostream>

int main()
{
    point p{2, 4};                                     // <-- cannot be const
    const point vec{1, 2};                             // <-- can be const
    p.move(vec);
    std::cout << '(' << p.x() << ',' << p.y() << ")\n";
    return 0;
}
