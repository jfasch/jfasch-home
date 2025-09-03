#include "sensors.h"
#include <iostream>

int main()
{
    MySensor ms{37.3, 0.25};

    Sensor* ps = &ms;

    double value = ps->get_value();                    // <-- dynamic dispatch to MySensor::get_value()
    std::cout << value << std::endl;

    return 0;
}
