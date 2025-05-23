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

int main()
{
    Sensor s;
    double value = s.get_value();
    std::cout << "got value " << value << std::endl;
    return 0;
}
