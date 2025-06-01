#include "sensors.h"
#include <iostream>

int main()
{
    Sensor s{36.4};
    double value = s.get_value();                      // <-- Sensor::get_value()
    std::cout << "Sensor value: " << value << std::endl;

    MySensor ms{37.3, 0.25};
    value = ms.get_value();                            // <-- MySensor::get_value()
    std::cout << "MySensor value " << value << std::endl;

    return 0;
}
