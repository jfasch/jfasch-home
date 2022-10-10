#include "thermometer-const.h"
#include <iostream>


int main()
{
    ThermometerConst th(42.7);
    std::cout << th.get_temperature() << std::endl;

    return 0;
}
