#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, basic)
{
    std::map<std::string, std::unique_ptr<Sensor>> sensors;
    
    RandomSensor* rs1 = new RandomSensor{20, 40};
    RandomSensor* rs2 = new RandomSensor{10, 30};
    ConstantSensor* cs = new ConstantSensor{36.5};

    // if this threw we'd leak memory of sensor objects
    auto temp = rs1->get_temperature();
    ASSERT_TRUE(temp>=20 && temp<=40);

    sensors["rand1"] = std::unique_ptr<Sensor>{rs1};
    sensors["rand2"] = std::unique_ptr<Sensor>{rs2};
    sensors["const"] = std::unique_ptr<Sensor>{cs};
}
