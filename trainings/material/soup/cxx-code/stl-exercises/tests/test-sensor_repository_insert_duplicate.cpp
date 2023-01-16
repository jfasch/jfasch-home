#include <gtest/gtest.h>

#include <sensor-random.h>
#include <sensor-const.h>

#include <sensor-repo.h>                               // <--- implement this

TEST(stl_exercises_suite, sensor_repository_insert_duplicate)
{
    SensorRepository repo;
    repo.add_sensor("Ofen", new RandomSensor(2.3, 666.1));
    repo.add_sensor("Weltraum", new ConstantSensor(-273.15));

    bool inserted;
    Sensor* s;

    s = new ConstantSensor(0);
    inserted = repo.add_sensor("Ofen", s);             // <--- duplicate, ownership not taken
    ASSERT_FALSE(inserted);
    ASSERT_EQ(repo.size(), 2);
    delete s;                                          // <--- avoid memory leak (still have ownership)

    s = new ConstantSensor(-100);
    inserted = repo.add_sensor("Mond", s);             // <--- sucess, ownership taken by repo
    ASSERT_TRUE(inserted);
    ASSERT_EQ(repo.size(), 3);
}
