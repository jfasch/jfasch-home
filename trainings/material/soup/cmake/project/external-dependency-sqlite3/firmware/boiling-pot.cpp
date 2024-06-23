#include <boiling-pot.h>
#include <sensor-w1.h>
#include <sysfs-switch.h>

#include <iostream>
#include <memory>
#include <unistd.h>


class StdOutSwitch : public Switch
{
public:
    void set_state(bool state) override
    {
        std::cout << (state? "ON" : "OFF") << '\n';
    }
};

int main(int argc, char** argv)
{
    std::cout << argc << std::endl;
    if (argc != 2 && argc != 3) {
        std::cerr << "Usage: " << argv[0] << " TEMPERATURE-FILE [GPIO-NUMBER]\n";
        std::cerr << "    TEMPERATURE-FILE   contains temperature in milli-celsius\n";
        std::cerr << "    GPIO-NUMBER        gpio number (as per raspi pinout)\n";
        std::cerr << "                       default stdout messages\n";
        return 1;
    }

    std::string temperature_file = argv[1];
    int gpio = -1;
    if (argc == 3)
        gpio = std::stoi(argv[2]);

    auto sensor = std::make_unique<W1Sensor>(temperature_file);
    std::unique_ptr<Switch> switcH;
    if (gpio >= 0)
        switcH = std::make_unique<SysFSGPIOSwitch>(gpio);
    else
        switcH = std::make_unique<StdOutSwitch>();


    BoilingPot pot(std::move(sensor), std::move(switcH));

    pot.heat(37.5);

    while (true) {
        sleep(1);
        pot.check();
    }

    return 0;
}
