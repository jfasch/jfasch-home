#include <sensor-const.h>
#include <sensor-random.h>
#include <sink-terminal.h>
#include <data-logger.h>
#include <sink-MQTT.h>
#include <MQTT_publisher.h>

#include <map>
#include <iostream>
#include <unistd.h>


int main()
{
    ConstantSensor bottom_left(37.5);
    ConstantSensor bottom_right(-273.15);
    RandomSensor top_left(0, 666);
    RandomSensor top_right(-273.15, 0);

    SensorConfig config;
    config.addSensor("bl", &bottom_left);
    config.addSensor("br", &bottom_right);
    config.addSensor("tl", &top_left);
    config.addSensor("tr", &top_right);
    
    //SinkTerminal sink;
    MQTTPublisher mqtt_pub("localhost", 1883, "2024-06-18");
    SinkMQTT sink(mqtt_pub);
    DataLogger logger(&config, &sink, 1000/*ms*/);
    logger.startLogging();

    return 0;
}
