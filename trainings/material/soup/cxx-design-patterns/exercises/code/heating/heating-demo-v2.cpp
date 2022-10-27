#include "sensor-reader.h"

#include <sensor-const.h>
#include <sensor-random.h>

#include <chrono>
#include <thread>
#include <map>
#include <iostream>

using namespace std::chrono_literals;


class DemoLogger : public SensorReader::Logger
{
public:
    void log(const std::string& msg) override
    {
        std::cerr << "DEMO-LOGGER: " << msg << std::endl;
    }
};

class DemoValueStore : public SensorReader::ValueStore
{
public:
    void set(const std::string& name, double value) override
    {
        std::cerr << "DEMO-STORE: setting " << name << " = " << value << std::endl;
    }
    
private:
    std::map<std::string/*name*/, double/*temperature*/> _store;
};


int main()
{
    DemoLogger logger;
    DemoValueStore store;
    SensorReader::Sensors sensors{
        {"sensorA", new RandomSensor(34.2, 41.3)},
        {"sensorB", new ConstantSensor(4)},
        {"sensorC", new RandomSensor(100, 200000)},
    };
    
    SensorReader rdr(
        sensors,
        logger,
        store
    );

    for (auto round: {1,2,3,4,5}) {
        std::cout << "*** Round " << round << " ..." << std::endl;
        rdr.doit();
        std::this_thread::sleep_for(0.5s);
    }

    return 0;
}
