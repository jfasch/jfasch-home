#ifndef __HAVE_HISTOGRAM_H__
#define __HAVE_HISTOGRAM_H__

#include "thermometer.h"

#include <unistd.h>
#include <iostream>
#include <vector>


template <typename Thermometer>
std::vector<double> make_histogram(const Thermometer& th, int n_samples, int interval)
{
    std::vector<double> ret;
    while (n_samples--) {
        std::cout << '.' << std::flush;
        ret.push_back(th.get_temperature());
        if (n_samples)
            sleep(interval);
    }
    std::cout << std::endl;
    return ret;
}

#endif
