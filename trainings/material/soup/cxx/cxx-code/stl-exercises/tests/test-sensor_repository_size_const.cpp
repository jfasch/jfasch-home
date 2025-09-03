#include <gtest/gtest.h>

#include <sensor-random.h>
#include <sensor-const.h>
#include <sensor-repo.h>

TEST(stl_exercises_suite, sensor_repository_size_const)
{
    const SensorRepository repo;
    ASSERT_EQ(repo.size(), 0);
}
