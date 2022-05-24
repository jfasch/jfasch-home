#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>

class HoldsASensor
{
public:
    HoldsASensor(std::unique_ptr<Sensor>&& s)
    : _sensor(std::move(s)) {}

private:
    std::unique_ptr<Sensor> _sensor;
};

static std::unique_ptr<Sensor> create_constant_sensor(double temp)
{
    return std::make_unique<ConstantSensor>(temp);
}

TEST(unique_ptr_suite, taking_ownership_in_own_code)
{
    auto has = HoldsASensor(create_constant_sensor(2));
}
