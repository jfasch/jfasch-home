#include <gtest/gtest.h>

#include <sensor-w1.h>

#include <cstdlib>
#include <unistd.h>

#include <stdexcept>

using namespace std;


struct w1_sensor_suite : public ::testing::Test
{
    void SetUp() override
    {
        char filename_pattern[] = "w1_sensor_suite-XXXXXX";
        
        fd = mkstemp(filename_pattern);
        if (fd == -1)
            throw runtime_error("nix mkstemp()");

        filename = filename_pattern;
    }

    void TearDown() override
    {
        if (fd != -1) {
            close(fd);
            unlink(filename.c_str());
        }
    }

    int fd;
    string filename;

    void write_temperature(double temperature)
    {
        unsigned temp_milli = temperature * 1000;

        string content = to_string(temp_milli);

        off_t pos = ::lseek(fd, 0, SEEK_SET);
        ASSERT_EQ(pos, 0);

        ssize_t nwritten = ::write(fd, content.c_str(), content.size());
        ASSERT_EQ(nwritten, content.size());
    }
};

TEST_F(w1_sensor_suite, test_read_sensor)
{
    write_temperature(42.666);

    W1Sensor sensor(filename);
    ASSERT_FLOAT_EQ(sensor.get_temperature(), 42.666);
}
