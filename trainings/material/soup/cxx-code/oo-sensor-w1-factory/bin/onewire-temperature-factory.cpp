#include <sensor-w1-factory.h>

#include <iostream>
#include <string>
#include <unistd.h>


int main(int argc, char** argv)
{
    if (! (argc == 4 || argc == 5)) {
        std::cerr << argv[0] <<  " <basedir> <address-in-hex> [interval]" << std::endl;
        std::cerr << "    " << "basedir                 ... e.g. /sys/bus/w1" << std::endl;
        std::cerr << "    " << "address-in-hex          ... 0xdeadbeef" << std::endl;
        std::cerr << "    " << "interval                ... in seconds" << std::endl;
        std::cerr << "    " << "n-iterations (optional) ... number of measurements" << std::endl;
        std::cerr << "    " << "                            before termination" << std::endl;
        return 42;
    }
    
    std::string basedir = argv[1];
    uint64_t addr = std::stoul(argv[2]);
    int interval = std::stoi(argv[3]);

    int niterations = -1;

    if (argc == 5)
        niterations = std::stoi(argv[4]);

    W1SensorFactory factory(basedir);

    W1Sensor* sensor = factory.find_by_address(addr);

    int iteration = 0;
    while (niterations == -1 || iteration++ < niterations) {
        std::cout << sensor->get_temperature() << std::endl;

        unsigned int time_remaining = sleep(interval);
        if (time_remaining != 0)
            std::cerr << "did not sleep " << interval << " seconds, " << time_remaining << " remaining" << std::endl;
    }

    return 0;
}
