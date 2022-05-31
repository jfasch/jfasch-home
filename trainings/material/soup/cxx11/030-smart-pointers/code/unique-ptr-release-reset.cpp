#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, release)
{
    auto raw = new RandomSensor{20, 30};
    auto ptr = std::unique_ptr<Sensor>(raw);

    auto raw1 = ptr.release();

    ASSERT_EQ(raw1, raw);
    ASSERT_EQ(ptr.get(), nullptr);

    // me being owner now!
    delete raw1;
}

TEST(unique_ptr_suite, reset)
{
    std::unique_ptr<Sensor> ptr = std::make_unique<RandomSensor>(20, 30);

    ptr.reset(new ConstantSensor{15}); // raw1 gone
    ptr.reset();  // all gone
    
    ASSERT_EQ(ptr.get(), nullptr);
}
