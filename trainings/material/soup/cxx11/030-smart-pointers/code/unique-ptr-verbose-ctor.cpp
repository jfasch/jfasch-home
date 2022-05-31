#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, verbose_ctor)
{
    std::unique_ptr<Sensor> rs1{new RandomSensor{20, 40}};
    std::unique_ptr<Sensor> rs2{new RandomSensor{10, 30}};
    std::unique_ptr<Sensor> cs{new ConstantSensor{36.5}};
}

