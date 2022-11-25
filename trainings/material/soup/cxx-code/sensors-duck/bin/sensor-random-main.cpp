#include <sensor-random.h>
#include <iostream>

int main()
{
    RandomSensor s(7, 42);
    std::cout << s.get_temperature() << std::endl;

    return 0;
}
