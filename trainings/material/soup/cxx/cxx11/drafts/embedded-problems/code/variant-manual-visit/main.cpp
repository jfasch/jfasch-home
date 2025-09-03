#include "sensors.h"
#include "avg.h"
#include <iostream>

int main()
{
    Sensor sensors[] = {Sensor1{42.1}, Sensor2{37.5}};
    std::cout << average(sensors) << std::endl;
    return 0;
}
