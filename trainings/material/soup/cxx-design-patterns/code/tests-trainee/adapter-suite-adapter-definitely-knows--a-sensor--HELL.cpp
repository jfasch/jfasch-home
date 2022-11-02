#include <gtest/gtest.h>

#include <sensor-A.h>
#include <sensor-A-const.h>
#include <sensor-A-adapter.h>
#include <sensor.h>


class AVariableSensor : public ASensor
{
public:
    AVariableSensor(double initial_value)
    : _value(initial_value) {}

    void change_temperature(double v)
    {
        _value = v;
    }

    virtual double get_temperature_fahrenheit() 
    {
        return _value;
    }

private:
    double _value;
};

TEST(adapter_suite, adapter__definitely_knows__a_sensor__HELL)
{
    AVariableSensor sensor_from_a(36.5);
    ASensor_Adapter a_adapter(&sensor_from_a);

    ASSERT_FLOAT_EQ(a_adapter.get_temperature(), (36.5 - 32) * 5/9);

    sensor_from_a.change_temperature(42.7);

    ASSERT_FLOAT_EQ(a_adapter.get_temperature(), (42.7 - 32) * 5/9);
}
