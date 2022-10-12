#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>

TEST(shared_ptr_suite, basic_make_shared)
{
    std::map<std::string, std::shared_ptr<Sensor>> sensors;
    
    auto rs1 = std::make_shared<RandomSensor>(20, 40);
    auto rs2 = std::make_shared<RandomSensor>(10, 30);
    auto cs = std::make_shared<ConstantSensor>(36.5);

    auto temp = rs1->get_temperature();
    ASSERT_TRUE(temp>=20 && temp<=40);

    sensors["rand1"] = rs1;
    sensors["rand2"] = rs2;
    sensors["const"] = cs;

    // shared ownership: can access sensors from map *and* from
    // outside references
    ASSERT_DOUBLE_EQ(cs->get_temperature(), 36.5);
    ASSERT_DOUBLE_EQ(sensors["const"]->get_temperature(), 36.5);
}

