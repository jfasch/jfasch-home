#include <sensor-const.h>
#include <sensor-random.h>
#include <sink-terminal.h>
#include <data-logger.h>

#include <memory>


int main()
{
    auto bottom_left = std::make_unique<ConstantSensor>(37.5);
    auto bottom_right = std::make_unique<ConstantSensor>(-273.15);
    auto top_left = std::make_unique<RandomSensor>(0, 666);
    auto top_right = std::make_unique<RandomSensor>(-273.15, 0);

    SensorConfig config;
    config.add_sensor("bl", std::move(bottom_left));
    config.add_sensor("br", std::move(bottom_right));
    config.add_sensor("tl", std::move(top_left));
    config.add_sensor("tr", std::move(top_right));
    
    auto sink = std::make_unique<SinkTerminal>();
    DataLogger logger(config, std::move(sink), 1000/*ms*/);
    logger.start_logging();

    return 0;
}
