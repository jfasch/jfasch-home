#include "sensors.h"
#include <iostream>

int main()
{
    Sensor* s = new MySensor{37.3};
    delete s;                                          // <-- base pointer used to free derived object
    return 0;
}
