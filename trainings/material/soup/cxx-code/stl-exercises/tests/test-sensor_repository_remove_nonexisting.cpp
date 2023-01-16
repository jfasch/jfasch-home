#include <gtest/gtest.h>

#include <sensor-random.h>
#include <sensor-const.h>
#include <sensor-repo.h>                               // <--- implement this

TEST(stl_exercises_suite, sensor_repository_remove_nonexisting)
{
    SensorRepository repo;
    repo.add_sensor("Ofen", new RandomSensor(2.3, 666.1));
    repo.add_sensor("Weltraum", new ConstantSensor(-273.15));

    bool removed;

    removed = repo.remove_sensor("Mond");              // <--- implement this
    ASSERT_FALSE(removed);
    ASSERT_EQ(repo.size(), 2);

    removed = repo.remove_sensor("Ofen");              // <--- implement this
    ASSERT_TRUE(removed);
    ASSERT_EQ(repo.size(), 1);
}
