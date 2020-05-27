#ifndef __HAVE_HISTOGRAM_H__
#define __HAVE_HISTOGRAM_H__

#include "thermometer.h"

#include <iostream>
#include <vector>
#include <unistd.h>


template<typename Thermometer>
std::vector<double> make_histogram(
    const Thermometer& th,
    unsigned nsamples,
    unsigned interval)
{
    std::vector<double> hist;
    
    while (nsamples--) {
        std::cerr << '.' << std::flush;
        sleep(interval);
        hist.push_back(th.get_temperature());
    }
    std::cerr << std::endl;
    return hist;
}

#endif

