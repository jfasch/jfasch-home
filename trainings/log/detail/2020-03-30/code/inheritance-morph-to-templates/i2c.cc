#include "thermometer.h"
#include "histogram.h"

#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char** argv)
{
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << "<sda> <scl> <addr>" << endl;
        return 1;
    }

    unsigned int sda, scl, addr;
    
    try {
        sda = std::stol(argv[1]);
    }
    catch (const invalid_argument&) {
        cerr << "nix sda" << endl;
        return 1;
    }

    try {
        scl = std::stol(argv[2]);
    }
    catch (const invalid_argument&) {
        cerr << "nix scl" << endl;
        return 1;
    }

    try {
        addr = std::stol(argv[3]);
    }
    catch (const invalid_argument&) {
        cerr << "nix addr" << endl;
        return 1;
    }

    I2CThermometer th(sda, scl, addr);

    vector<double> temperatures = make_histogram(th, /*n_samples*/10, /*interval*/1);
    for (auto t: temperatures)
        cout << t << endl;

    return 0;
}
