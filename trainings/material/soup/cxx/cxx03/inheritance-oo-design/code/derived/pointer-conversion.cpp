#include "sensors.h"
#include <iostream>

int main()
{
    MySensor ms{37.3, 0.25};

    Sensor* ps = &ms;                                  // <-- Conversion to base class
                                                       // <-- *definition of inheritance*

    double value = ps->get_value();                    // <-- ???
    std::cout << value << std::endl;

    return 0;
}
