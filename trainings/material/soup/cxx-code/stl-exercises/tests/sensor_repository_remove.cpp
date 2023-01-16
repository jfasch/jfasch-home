#include <gtest/gtest.h>

#include <sensor-random.h>
#include <sensor-const.h>
#include <sensor-repo.h>

TEST(stl_exercises_suite, sensor_repository_remove)
{
    SensorRepository repo;
    repo.add_sensor("Ofen", new RandomSensor(2.3, 666.1));
    repo.add_sensor("Weltraum", new ConstantSensor(-273.15));

    repo.remove_sensor("Ofen");
    ASSERT_EQ(repo.size(), 1);
    ASSERT_EQ(repo.get_sensor("Ofen"), nullptr);

    repo.remove_sensor("Weltraum");
    ASSERT_EQ(repo.size(), 0);
    ASSERT_EQ(repo.get_sensor("Weltraum"), nullptr);
}
