#include "sensors.h"

#include <map>
#include <memory>
#include <thread>
#include <chrono>
#include <iostream>


int main()
{
    std::map<std::string, std::shared_ptr<Sensor>> sensors;
    sensors["rand1"] = std::make_shared<RandomSensor>(20, 40);
    sensors["rand2"] = std::make_shared<RandomSensor>(10, 30);
    sensors["const"] = std::make_shared<ConstantSensor>(36.5);

    std::weak_ptr<Sensor> sensor_ref{sensors["rand1"]};

    std::thread measurement_thread([sensor_ref]() {
        while (true) {
            if (auto sensor = sensor_ref.lock()) {
                std::cout << sensor->get_temperature() << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(700));
            }
            else {
                std::cout << "terminating" << std::endl;
                break;
            }
        }
    });

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "removing sensor" << std::endl;
    sensors.erase("rand1");

    measurement_thread.join();

    return 0;
}
