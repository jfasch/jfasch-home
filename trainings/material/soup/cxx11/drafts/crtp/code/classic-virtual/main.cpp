#include "sensors.h"
#include "avg.h"

#include <iostream>

int main()
{
    Sensor1 s1{37.1};
    Sensor2 s2{42.666};

    Sensor* sensors[] = {&s1, &s2};

    std::cout << average(sensors) << std::endl;
    return 0;
}
