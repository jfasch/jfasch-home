#include "sensors.h"
#include "avg.h"
#include <memory>
#include <vector>
#include <iostream>

template <typename SensorType>
std::shared_ptr<SensorType> make_sensor(double temperature)
{
    void* mem = std::aligned_alloc(alignof(SensorType), 10*1024*1024);
    SensorType* ptr = new (mem) SensorType(temperature);
    return std::shared_ptr<SensorType>(ptr, [](auto p) { std::free(p); });
}

int main()
{
    auto s0 = make_sensor<Sensor1>(37.4);
    auto s1 = make_sensor<Sensor2>(666.8);
    auto s2 = make_sensor<Sensor1>(-273.15);
    auto s3 = make_sensor<Sensor2>(3.141);
    auto s4 = make_sensor<Sensor1>(42.1);
    auto s5 = make_sensor<Sensor2>(42.2);

    std::vector<std::shared_ptr<Sensor>> sensors{s0, s1, s2, s3, s4, s5};

    std::cout << average(sensors) << '\n';
    return 0;
}
