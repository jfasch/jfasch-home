#include <sensor-const.h>
#include <iostream>

int main()
{
    ConstantSensor s(42.7);
    std::cout << s.get_temperature() << std::endl;

    return 0;
}
