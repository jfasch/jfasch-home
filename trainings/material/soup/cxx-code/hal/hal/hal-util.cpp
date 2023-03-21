#include "hal-util.h"

#include <time.h>


namespace jf::hal
{

timespec ms_to_timespec(unsigned long ms)
{
    static const long ONE_SECOND_NS = 1000*1000*1000;
    long nanos = 1000*1000*ms;
    time_t secs = nanos / ONE_SECOND_NS;
    nanos %= ONE_SECOND_NS;

    return { secs, nanos };
}

}
