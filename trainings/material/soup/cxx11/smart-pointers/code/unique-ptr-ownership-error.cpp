#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, ownership_error)
{
    std::map<std::string, std::unique_ptr<Sensor>> sensors;
    
    std::unique_ptr<Sensor> rs1{new RandomSensor{20, 40}};
    std::unique_ptr<Sensor> rs2{new RandomSensor{10, 30}};
    std::unique_ptr<Sensor> cs{new ConstantSensor{36.5}};

    auto temp = rs1->get_temperature();
    ASSERT_TRUE(temp>=20 && temp<=40);

    sensors["rand1"] = rs1;
    sensors["rand2"] = rs2;
    sensors["const"] = cs;
}
