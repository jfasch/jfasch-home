#include <iostream>

class Sensor
{
public:
    virtual double get_value() const = 0;
};

class MySensor : public Sensor
{
public:
    MySensor(double value)
    : _value(new double{value}) {}                     // <-- allocation
    ~MySensor()
    {
        std::cout << "MySensor::~MySensor()" << std::endl;
        delete _value;                                 // <-- deallocation
    }
    double get_value() const override
    {
        return *_value;
    }
private:
    double* _value;
};
