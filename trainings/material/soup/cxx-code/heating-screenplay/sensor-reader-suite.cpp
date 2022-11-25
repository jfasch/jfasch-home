#include <gtest/gtest.h>

#include "sensor-reader.h"
#include <sensor-const.h>
#include <map>

namespace {

struct MockLogger : public SensorReader::Logger
{
    void log(const std::string& msg) override
    {
        lines_logged++;
    }

    int lines_logged = 0;
};

struct MockValueStore : public SensorReader::ValueStore
{
    void set(const std::string& name, double value)
    {
        values[name] = value;
    }
    std::map<const std::string, double> values;
};

}


TEST(sensorreader_suite, basics)
{
    MockLogger logger;
    MockValueStore store;
    SensorReader::Sensors sensors {
        {"sensor1", new ConstantSensor(1) },
        {"sensor2", new ConstantSensor(2) },
    };

    SensorReader rdr(sensors, logger, store);
    rdr.doit();

    ASSERT_FLOAT_EQ(store.values["sensor1"], 1);
    ASSERT_FLOAT_EQ(store.values["sensor2"], 2);
}
