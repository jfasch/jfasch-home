#include <iostream>

class Sensor
{
public:
    virtual double get_value() const = 0;              // <-- purposely *no* implementation
};

class MySensor : public Sensor
{
public:
    MySensor(double base, double correction)
    : _base{base},
      _correction{correction} {}

    double get_value() const override                  // <-- overriding method
    {
        double value = _base + _correction;
        std::cout << "MySensor::get_value(): " << value << std::endl;
        return value;
    }
private:
    double _base;
    double _correction;
};
