#include <gtest/gtest.h>

#include <sensor-random.h>
#include <sensor-const.h>
#include <sensor-repo.h>

TEST(stl_exercises_suite, sensor_repository_lookup_positive)
{
    SensorRepository repo;
    repo.add_sensor("Ofen", new RandomSensor(2.3, 666.1));
    repo.add_sensor("Weltraum", new ConstantSensor(-273.15));

    Sensor* s;
    double temperature;

    s = repo.get_sensor("Ofen");
    temperature = s->get_temperature();

    ASSERT_GE(temperature, 2.3);
    ASSERT_LE(temperature, 666.1);

    s = repo.get_sensor("Weltraum");
    temperature = s->get_temperature();

    ASSERT_FLOAT_EQ(temperature, -273.15);
}
