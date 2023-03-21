#include "hal-delay.h"

#include "hal-util.h"

#include <cassert>


namespace jf::hal {

void delay_ms(size_t milliseconds)
{
    timespec ts = ms_to_timespec(milliseconds);
    int error = nanosleep(&ts, nullptr);
    assert(!error);
}

}
