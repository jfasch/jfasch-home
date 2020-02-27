#ifndef HAVE_MSG_H
#define HAVE_MSG_H

#include <stdint.h>


struct msg
{
    uint64_t timestamp;
    double value;
    uint32_t channel;
};

#endif

