#include <gtest/gtest.h>

#include <sensor-random.h>
#include <sensor-const.h>
#include <sensor-repo.h>

TEST(stl_exercises_suite, sensor_repository_insert)
{
    SensorRepository repo;
    repo.add_sensor("Ofen", new RandomSensor(2.3, 666.1));
    repo.add_sensor("Weltraum", new ConstantSensor(-273.15));

    ASSERT_EQ(repo.size(), 2);
}

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

TEST(stl_exercises_suite, sensor_repository_lookup_negative)
{
    SensorRepository repo;
    repo.add_sensor("Ofen", new RandomSensor(2.3, 666.1));
    repo.add_sensor("Weltraum", new ConstantSensor(-273.15));

    Sensor* s = repo.get_sensor("Nowhere");
    ASSERT_EQ(s, nullptr);
}

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






TEST(stl_exercises_suite, sensor_repository_size_const)
{
    const SensorRepository repo;
    ASSERT_EQ(repo.size(), 0);
}

TEST(stl_exercises_suite, sensor_repository_insert_duplicate)
{
    SensorRepository repo;
    repo.add_sensor("Ofen", new RandomSensor(2.3, 666.1));
    repo.add_sensor("Weltraum", new ConstantSensor(-273.15));

    bool inserted;

    inserted = repo.add_sensor("Ofen", new ConstantSensor(0));
    ASSERT_FALSE(inserted);
    ASSERT_EQ(repo.size(), 2);

    inserted = repo.add_sensor("Mond", new ConstantSensor(-100));
    ASSERT_TRUE(inserted);
    ASSERT_EQ(repo.size(), 3);
}

TEST(stl_exercises_suite, sensor_repository_remove_nonexisting)
{
    SensorRepository repo;
    repo.add_sensor("Ofen", new RandomSensor(2.3, 666.1));
    repo.add_sensor("Weltraum", new ConstantSensor(-273.15));

    bool removed;

    removed = repo.remove_sensor("Mond");
    ASSERT_FALSE(removed);
    ASSERT_EQ(repo.size(), 2);

    removed = repo.remove_sensor("Ofen");
    ASSERT_TRUE(removed);
    ASSERT_EQ(repo.size(), 1);
}
