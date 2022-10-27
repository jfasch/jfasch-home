#include <sensor-const.h>
#include <sensor-random.h>

#include <chrono>
#include <thread>
#include <vector>
#include <map>
#include <iostream>

using namespace std::chrono_literals;


class DemoLogger
{
public:
    void log(const std::string& msg)
    {
        std::cerr << "DEMO-LOGGER: " << msg << std::endl;
    }
};

class DemoValueStore
{
public:
    void set(const std::string& name, double value)
    {
        std::cerr << "DEMO-STORE: setting " << name << " = " << value << std::endl;
    }
    
private:
    std::map<std::string/*name*/, double/*temperature*/> _store;
};


class SensorReader
{
public:
    using NamedSensor = std::pair<std::string, Sensor*>;
    using Sensors = std::vector<NamedSensor>;

public:
    SensorReader(
        const Sensors& sensors,
        DemoLogger& logger,
        DemoValueStore& store)
    : _sensors(sensors),
      _logger(logger),
      _value_store(store) {}

    void doit()
    {
        for (auto [name, sensor]: _sensors){
            _logger.log(name);
            double temperature = sensor->get_temperature();
            _value_store.set(name, temperature);
        }
    }
    
private:
    std::vector<NamedSensor> _sensors;    
    DemoLogger& _logger;
    DemoValueStore& _value_store;
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
