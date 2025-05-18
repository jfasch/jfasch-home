#include "sensor-mock.h"
#include "logger.h"

#include <unistd.h>

int main()
{
    MockSensor sensor{42.666};
    Logger logger(&sensor);

    while (true) {
        logger.log_one();
        sleep(1);
    }
    return 0;
}
