#include "thermometer.h"
#include "histogram.h"

#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <sda> <scl> <addr>" << endl;
        return 1;
    }

    unsigned sda, scl, addr;

    try {
        sda = std::stoi(argv[1]);
    }
    catch (const std::invalid_argument& error) {
        cerr << "Nix SDA" << endl;
        return 1;
    }

    try {
        scl = std::stoi(argv[2]);
    }
    catch (const std::invalid_argument& error) {
        cerr << "Nix SCL" << endl;
        return 1;
    }

    try {
        addr = std::stoi(argv[3]);
    }
    catch (const std::invalid_argument& error) {
        cerr << "Nix ADDR" << endl;
        return 1;
    }

    I2CThermometer th(sda, scl, addr);
    std::vector<double> values = make_histogram(th, /*#samples*/10, /*interval(s)*/1);

    for (auto v: values)
        cout << v << endl;

    return 0;
}
