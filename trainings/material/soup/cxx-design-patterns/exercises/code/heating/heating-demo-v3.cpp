#include "sensor-reader.h"

#include "logger-demo.h"            // <--- pulled out to header
#include "valuestore-demo.h"        // <--- pulled out to header
#include "logger-dbus.h"            // <--- new header
#include "valuestore-dbus.h"        // <--- new header

#include <sensor-const.h>
#include <sensor-random.h>

#include <chrono>
#include <thread>
#include <memory>
#include <iostream>

using namespace std::chrono_literals;


int main(int argc, char** argv)
{
    std::unique_ptr<SensorReader::Logger> logger;
    std::unique_ptr<SensorReader::ValueStore> store;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " 'DEMO|DBUS'" << std::endl;
        return 1;
    }
    std::string environ = argv[1];
    if (environ == "DEMO") {
        logger.reset(new DemoLogger);
        store.reset(new DemoValueStore);
    }
    else if (environ == "DBUS") {
        logger.reset(new DBusLogger);
        store.reset(new DBusValueStore);
    }
    else {
        std::cerr << "Usage: " << argv[0] << " 'DEMO|DBUS'" << std::endl;
        return 1;
    }


    SensorReader::Sensors sensors{
        {"sensorA", new RandomSensor(34.2, 41.3)},
        {"sensorB", new ConstantSensor(4)},
        {"sensorC", new RandomSensor(100, 200000)},
    };
    
    SensorReader rdr(
        sensors,
        *logger,
        *store
    );

    for (auto round: {1,2,3,4,5}) {
        std::cout << "*** Round " << round << " ..." << std::endl;
        rdr.doit();
        std::this_thread::sleep_for(0.5s);
    }

    return 0;
}
