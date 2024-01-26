#pragma once

class Sensor
{
public:
    virtual ~Sensor() = default;
    virtual double get_temperature() = 0;
};
class Switch
{
public:
    virtual ~Switch() = default;
    virtual void set_state(bool state) = 0;
};

class Display
{
public:
    virtual ~Display() = default;
    virtual void show(double) = 0;
};

class Hysteresis
{
public:
    Hysteresis(Sensor* sensor, Switch* switcH,
               Display* display,                       // <--- passed a nullptr, mostly
               double low, double high)
    : _sensor(sensor),
      _switch(switcH),
      _display(display),
      _low(low),
      _high(high) {}

    void check()
    {
        double current_temperature = _sensor->get_temperature();
        if (current_temperature < _low)
            _switch->set_state(true); 
        else if (current_temperature > _high)
            _switch->set_state(false); 
        else { /* leave as-is */ }

        if (_display)
            _display->show(current_temperature);       // <--- not called, mostly
    }

private:
    Sensor* _sensor;
    Switch* _switch;
    Display* _display;
    double _low;
    double _high;
};
