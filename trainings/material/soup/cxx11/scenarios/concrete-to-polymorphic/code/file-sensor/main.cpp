// #include "sensor-file.h"                            // <-- Logger fails
#include "sensor-mock.h"
#include "logger.h"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main(int argc, const char** argv)
{
    MockSensor sensor{42.666};
    // FileSensor sensor{argv[1]};                     // <-- Logger fails
    Logger logger(&sensor);

    while (true) {
        logger.log_one();
        std::this_thread::sleep_for(0.5s);
    }
    return 0;
}
