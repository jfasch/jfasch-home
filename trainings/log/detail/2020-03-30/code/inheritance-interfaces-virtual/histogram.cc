#include "histogram.h"

#include <unistd.h>
#include <iostream>

using namespace std;


vector<double> make_histogram(const Thermometer& th, int n_samples, int interval)
{
    vector<double> ret;
    while (n_samples--) {
        cout << '.' << flush;
        ret.push_back(th.get_temperature());
        if (n_samples)
            sleep(interval);
    }
    cout << endl;
    return ret;
}
