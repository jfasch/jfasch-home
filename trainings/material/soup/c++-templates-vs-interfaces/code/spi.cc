#include "thermometer.h"
#include "histogram.h"

#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << " <mosi> <miso> <clk> <cs>" << endl;
        return 1;
    }

    unsigned mosi, miso, clk, cs;

    try {
        mosi = std::stoi(argv[1]);
    }
    catch (const std::invalid_argument& error) {
        cerr << "Nix MOSI" << endl;
        return 1;
    }

    try {
        miso = std::stoi(argv[2]);
    }
    catch (const std::invalid_argument& error) {
        cerr << "Nix MISO" << endl;
        return 1;
    }

    try {
        clk = std::stoi(argv[3]);
    }
    catch (const std::invalid_argument& error) {
        cerr << "Nix CLK" << endl;
        return 1;
    }

    try {
        cs = std::stoi(argv[4]);
    }
    catch (const std::invalid_argument& error) {
        cerr << "Nix CS" << endl;
        return 1;
    }

    SPIThermometer th(mosi, miso, clk, cs);
    std::vector<double> values = make_histogram(th, /*#samples*/10, /*interval(s)*/1);

    for (auto v: values)
        cout << v << endl;

    return 0;
}
