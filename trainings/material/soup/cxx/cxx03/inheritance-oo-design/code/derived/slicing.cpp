#include "sensors.h"
#include <iostream>

int main()
{
    Sensor s{36.4};
    MySensor ms{37.3, 0.25};

    s = ms;                                            // <-- this is bad!

    double value = s.get_value();                      // <-- ???
    std::cout << value << std::endl;

    return 0;
}
