#include <iostream>

class Sensor
{
public:
    virtual ~Sensor() = default;                       // <-- empty!
    virtual double get_value() const = 0;
};

class MySensor : public Sensor
{
public:
    MySensor(double value)
    : _value(new double{value}) {}
    ~MySensor() override
    {
        std::cout << "MySensor::~MySensor()" << std::endl;
        delete _value;
    }
    double get_value() const override
    {
        return *_value;
    }
private:
    double* _value;
};
