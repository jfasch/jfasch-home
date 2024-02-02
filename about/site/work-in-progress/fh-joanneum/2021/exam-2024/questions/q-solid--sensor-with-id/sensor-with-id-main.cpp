#include "sensor-w1.h"
#include <unistd.h>
#include <iostream>

int main()
{
    W1Sensor sensor(/*id*/ 666, // unused in this program
                    /*w1_address*/ 0xdeadbeefUL);

    while (true) {
        double temperature = sensor.get_temperature();
        std::cout << temperature << std::endl;

        sleep(1);
    }

    return 0;
}

