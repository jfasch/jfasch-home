#include <iostream>

class Sensor
{
public:
    Sensor(double value) : _value{value} {}
    double get_value() const
    {
        std::cout << "Sensor::get_value(): " << _value << std::endl;
        return _value;
    }
private:
    double _value;
};

class MySensor : public Sensor                         // <-- MySensor *is-a* Sensor
{
public:
    MySensor(double basetemp, double correction)
    : Sensor{basetemp},
      _correction{correction} {}

    double get_value() const
    {
        double value = Sensor::get_value() + _correction;
        std::cout << "MySensor::get_value(): " << value << std::endl;
        return value;
    }
private:
    double _correction;
};
