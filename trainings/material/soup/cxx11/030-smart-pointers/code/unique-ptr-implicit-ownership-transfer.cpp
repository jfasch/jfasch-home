#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>

static std::unique_ptr<Sensor> create_random_sensor(double low, double high)
{
    // do some boilerplate (like going through config) before creating
    // sensor object
    return std::make_unique<RandomSensor>(low, high);
}
static std::unique_ptr<Sensor> create_constant_sensor(double temp)
{
    // do some boilerplate (like going through config) before creating
    // sensor object
    return std::make_unique<ConstantSensor>(temp);
}

TEST(unique_ptr_suite, implicit_ownership_transfer)
{
    std::map<std::string, std::unique_ptr<Sensor>> sensors;

    sensors["rand1"] = create_random_sensor(20, 40);
    sensors["rand2"] = create_random_sensor(20, 40);
    sensors["const"] = create_constant_sensor(36.5);
}
