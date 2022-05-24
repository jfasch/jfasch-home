#include <gtest/gtest.h>

#include "sensors.h"

TEST(intro_suite, leak)
{
    std::map<std::string, Sensor*> sensors;

    RandomSensor* rs1 = new RandomSensor(20, 40);
    RandomSensor* rs2 = new RandomSensor(10, 30);
    ConstantSensor* cs = new ConstantSensor(36.5);

    sensors["rand1"] = rs1;
    sensors["rand2"] = rs2;
    sensors["const"] = cs;

    // leaking sensor objects
}

