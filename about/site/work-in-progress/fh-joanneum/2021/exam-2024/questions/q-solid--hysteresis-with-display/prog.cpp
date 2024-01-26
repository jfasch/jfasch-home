#include "hysteresis-with-display.h"


class MockSensor : public Sensor
{
public:
    MockSensor(double initial_temperature) : _temperature(initial_temperature) {}
    double get_temperature() { return _temperature; }
    void set_temperature(double temperature);

private:
    double _temperature;
};

class MockSwitch : public Switch
{
public:
    MockSwitch(bool initial_state) : _state(initial_state) {}
    virtual void set_state(bool state) { _state = state; }
private:
    bool _state;
};

class MockDisplay : public Display
{
public:
    MockDisplay(double initial_value) : _value(initial_value) {}
    void show(double value)
    {
        _value = value;
    }
private:
    double _value;
};


int main()
{
    MockSensor sensor(37.5);
    MockSwitch sw(false);

    Hysteresis hy(&sensor, &sw, nullptr, 30, 34);

    hy.check();

    return 0;
}
