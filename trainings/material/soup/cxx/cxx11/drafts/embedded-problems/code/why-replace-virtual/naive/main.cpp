#include "sensors.h"
#include "avg.h"
#include <memory>
#include <vector>
#include <iostream>

int main()
{
    auto s0 = std::make_shared<Sensor1>(37.4);
    auto s1 = std::make_shared<Sensor2>(666.8);
    auto s2 = std::make_shared<Sensor1>(-273.15);
    auto s3 = std::make_shared<Sensor2>(3.141);
    auto s4 = std::make_shared<Sensor1>(42.1);
    auto s5 = std::make_shared<Sensor2>(42.2);

    std::vector<std::shared_ptr<Sensor>> sensors{s0, s1, s2, s3, s4, s5};

    std::cout << average(sensors) << '\n';
    return 0;
}
