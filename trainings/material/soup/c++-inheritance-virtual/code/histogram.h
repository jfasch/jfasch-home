#ifndef __HAVE_HISTOGRAM_H__
#define __HAVE_HISTOGRAM_H__

#include "thermometer.h"

#include <vector>


std::vector<double> make_histogram(
    const Thermometer& th,
    unsigned nsamples,
    unsigned interval);

#endif

