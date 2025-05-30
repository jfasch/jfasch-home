#include <iostream>


class Sensor
{
public:
    double get_value() const
    {
        std::cout << "Sensor::get_value()" << std::endl;
        return 36.5;
    }
};

class MySensor : public Sensor
{
public:
    double get_value() const
    {
        std::cout << "MySensor::get_value()" << std::endl;
        return 42.6;
    }
};

int main()
{
    Sensor s;
    double value = s.get_value();
    std::cout << "Sensor value: " << value << std::endl;

    MySensor ms;
    value = ms.get_value();
    std::cout << "MySensor value " << value << std::endl;

    return 0;
}
