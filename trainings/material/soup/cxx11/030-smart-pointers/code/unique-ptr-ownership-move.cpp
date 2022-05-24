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

    // invalidate outside object references, and move objects to be
    // owned by map
    sensors["rand1"] = std::move(rs1);
    sensors["rand2"] = std::move(rs2);
    sensors["const"] = std::move(cs);

    // outside references are gone
    ASSERT_EQ(rs1.get(), nullptr);
    ASSERT_EQ(rs2.get(), nullptr);
    ASSERT_EQ(cs.get(), nullptr);
}
