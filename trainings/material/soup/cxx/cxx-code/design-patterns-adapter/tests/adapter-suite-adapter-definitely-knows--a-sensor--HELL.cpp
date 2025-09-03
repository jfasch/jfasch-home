#include <gtest/gtest.h>

#include <sensor-fahrenheit.h>
#include <sensor-fahrenheit-const.h>
#include <sensor-fahrenheit-adapter.h>
#include <sensor.h>


class VariableFahrenheitSensor : public FahrenheitSensor
{
public:
    VariableFahrenheitSensor(double initial_value)
    : _value(initial_value) {}

    void change_temperature(double v)
    {
        _value = v;
    }

    double get_temperature_f() override
    {
        return _value;
    }

private:
    double _value;
};

TEST(adapter_suite, adapter__definitely_knows__a_sensor__HELL)
{
    VariableFahrenheitSensor fs(36.5);
    FahrenheitSensor_Adapter adapter(&fs);

    ASSERT_FLOAT_EQ(adapter.get_temperature(), (36.5 - 32) * 5/9);

    fs.change_temperature(42.7);

    ASSERT_FLOAT_EQ(adapter.get_temperature(), (42.7 - 32) * 5/9);
}
