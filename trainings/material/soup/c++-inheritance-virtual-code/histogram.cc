#include "histogram.h"

#include <unistd.h>
#include <iostream>

using namespace std;


std::vector<double> make_histogram(
    const Thermometer& th,
    unsigned nsamples,
    unsigned interval)
{
    std::vector<double> hist;
    
    while (nsamples--) {
        cerr << '.' << flush;
        sleep(interval);
        hist.push_back(th.get_temperature());
    }
    cerr << endl;
    return hist;
}
