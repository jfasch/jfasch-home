#include "thermometer-const.h"
#include "thermometer-random.h"
#include <iostream>

int main()
{
    ThermometerConst th_const(42.7);
    ThermometerRandom th_random(7, 42);

    Thermometer* thermometers[2];
    thermometers[0] = &th_const;
    thermometers[1] = &th_random;

    double sum = 0;
    unsigned int count = 0;
    for (int i=0; i<2; i++) {
        count++;
        sum += thermometers[i]->get_temperature();
    }

    double avg = sum/count;
    std::cout << avg << std::endl;

    return 0;
}
