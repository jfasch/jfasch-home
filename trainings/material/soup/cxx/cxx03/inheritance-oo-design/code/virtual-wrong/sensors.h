#include <iostream>

class Sensor
{
public:
    Sensor(double value) : _value{value} {}
    double get_value() const                           // <-- not a virtual method
    {
        std::cout << "Sensor::get_value(): " << _value << std::endl;
        return _value;
    }
private:
    double _value;
};

class MySensor : public Sensor
{
public:
    MySensor(double basetemp, double correction)
    : Sensor{basetemp},
      _correction{correction} {}

    virtual double get_value() const                   // <-- virtual, but too late down the hierarchy
    {
        double value = Sensor::get_value() + _correction;
        std::cout << "MySensor::get_value(): " << value << std::endl;
        return value;
    }
private:
    double _correction;
};
