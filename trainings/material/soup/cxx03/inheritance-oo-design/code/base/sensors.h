#include <iostream>

class Sensor
{
public:
    Sensor(double value) : _value{value} {}
    double get_value() const
    {
        std::cout << "Sensor::get_value(): " << _value << std::endl;
        return 36.5;
    }
private:
    double _value;
};
