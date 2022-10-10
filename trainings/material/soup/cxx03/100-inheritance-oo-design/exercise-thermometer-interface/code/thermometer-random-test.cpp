#include "thermometer-random.h"
#include <iostream>

int main()
{
    ThermometerRandom th(7, 42);
    std::cout << th.get_temperature() << std::endl;

    return 0;
}
