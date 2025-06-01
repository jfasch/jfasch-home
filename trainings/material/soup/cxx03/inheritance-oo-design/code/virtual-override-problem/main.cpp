#include "sensors.h"
#include <iostream>

int main()
{
    MySensor ms{37.3, 0.25};

    Sensor* ps = &ms;

    double value = ps->get_value();                    // <-- *not* overridden by MySensor
    std::cout << value << std::endl;

    return 0;
}
