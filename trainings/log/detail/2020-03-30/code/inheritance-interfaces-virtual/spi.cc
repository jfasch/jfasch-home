#include "thermometer.h"
#include "histogram.h"

#include <iostream>
#include <vector>

using namespace std;



int main(int argc, char** argv)
{
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << "<miso> <mosi> <clk> <cs>" << endl;
        return 1;
    }

    unsigned int miso, mosi, clk, cs;
    
    try {
        miso = std::stol(argv[1]);
    }
    catch (const invalid_argument&) {
        cerr << "nix miso" << endl;
        return 1;
    }

    try {
        mosi = std::stol(argv[2]);
    }
    catch (const invalid_argument&) {
        cerr << "nix mosi" << endl;
        return 1;
    }

    try {
        clk = std::stol(argv[3]);
    }
    catch (const invalid_argument&) {
        cerr << "nix clk" << endl;
        return 1;
    }

    try {
        cs = std::stol(argv[4]);
    }
    catch (const invalid_argument&) {
        cerr << "nix cs" << endl;
        return 1;
    }

    SPIThermometer th(miso, mosi, clk, cs);

    vector<double> temperatures = make_histogram(th, /*n_samples*/10, /*interval*/1);
    for (auto t: temperatures)
        cout << t << endl;

    return 0;
}
