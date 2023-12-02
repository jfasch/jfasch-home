#include "sensors.h"
#include "avg.h"
#include <vector>
#include <iostream>

int main()
{
    Sensor1 s1{42.1};
    Sensor2 s2{37.5};

    using Sensors = std::vector<Sensor>;
    Sensors sensors;
    sensors.push_back(std::move(s1));
    sensors.push_back(std::move(s2));
    std::cout << average(sensors) << std::endl;
    sensors.erase(sensors.begin());
    std::cout << average(sensors) << std::endl;

    return 0;
}
