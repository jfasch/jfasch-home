#include "sensor-mock.h"
#include "logger.h"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main()
{
    MockSensor sensor{42.666};
    Logger logger(&sensor);

    while (true) {
        logger.log_one();
        std::this_thread::sleep_for(0.5s);             // <-- cool
    }
    return 0;
}
