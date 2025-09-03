#include "sensors.h"
#include <iostream>

int main()
{
    Sensor s{36.4};
    double value = s.get_value();
    std::cout << "got value " << value << std::endl;
    return 0;
}
