#include "sensor-file.h"
#include "logger.h"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main(int argc, const char** argv)
{
    FileSensor sensor{argv[1]};
    Logger logger(&sensor);

    while (true) {
        logger.log_one();
        std::this_thread::sleep_for(0.5s);
    }
    return 0;
}
