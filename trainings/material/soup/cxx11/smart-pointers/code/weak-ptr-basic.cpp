#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>


TEST(weak_ptr_suite, basic)
{
    // original object, referenced via shared_ptr
    std::shared_ptr<Sensor> sensor{new RandomSensor{20, 40}};

    // borrowed reference: weak_ptr
    std::weak_ptr<Sensor> borrowed_sensor{sensor};

    // refcount still one
    ASSERT_EQ(sensor.use_count(), 1);

    auto another_reference = borrowed_sensor.lock();

    ASSERT_EQ(another_reference.get(), sensor.get());
    ASSERT_EQ(sensor.use_count(), 2);
}
