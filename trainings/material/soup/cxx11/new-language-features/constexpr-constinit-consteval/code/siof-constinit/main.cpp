#include "global-point-standalone.h"
#include "global-point-depends.h"

#include <iostream>

std::ostream& operator<<(std::ostream& o, const point& p)
{
    o << '(' << p.x() << ',' << p.y() << ')';
    return o;
}

int main()
{
    std::cout << "global_point_standalone: " << global_point_standalone << std::endl;
    std::cout << "global_point_depends: " << global_point_depends << std::endl;
    return 0;
}
