#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, make_unique_auto)
{
    auto rs1 = std::make_unique<RandomSensor>(20, 40);
    auto rs2 = std::make_unique<RandomSensor>(10, 30);
    auto cs = std::make_unique<ConstantSensor>(36.5);
}
