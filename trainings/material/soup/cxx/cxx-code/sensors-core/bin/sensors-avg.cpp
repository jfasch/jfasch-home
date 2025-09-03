#include <sensor-const.h>
#include <sensor-random.h>

#include <iostream>

int main()
{
    ConstantSensor cs(42.7);
    RandomSensor rs(7, 42);

    Sensor* sensors[2];
    sensors[0] = &cs;
    sensors[1] = &rs;

    double sum = 0;
    unsigned int count = 0;
    for (int i=0; i<2; i++) {
        count++;
        sum += sensors[i]->get_temperature();
    }

    double avg = sum/count;
    std::cout << avg << std::endl;

    return 0;
}
