#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>

TEST(shared_ptr_suite, basic)
{
    std::map<std::string, std::shared_ptr<Sensor>> sensors;
    
    std::shared_ptr<Sensor> rs1{new RandomSensor{20, 40}};
    std::shared_ptr<Sensor> rs2{new RandomSensor{10, 30}};
    std::shared_ptr<Sensor> cs{new ConstantSensor{36.5}};

    auto temp = rs1->get_temperature();
    ASSERT_TRUE(temp>=20 && temp<=40);

    sensors["rand1"] = rs1;
    sensors["rand2"] = rs2;
    sensors["const"] = cs;

    // shared ownership: cann access sensors from map *and* from
    // outside references
    ASSERT_DOUBLE_EQ(cs->get_temperature(), 36.5);
    ASSERT_DOUBLE_EQ(sensors["const"]->get_temperature(), 36.5);
}

