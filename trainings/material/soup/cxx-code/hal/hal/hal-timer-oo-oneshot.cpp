#include "hal-timer-oo-oneshot.h"

#include <string.h>
#include <assert.h>


namespace jf::hal
{

OneshotTimer::OneshotTimer(size_t milliseconds, User* u)
: Timer(u),
  _milliseconds(milliseconds) {}

void OneshotTimer::start()
{
    itimerspec ts = {
        {0,0}, // interval (none; this is a one-shot timer)
        ms_to_timespec(_milliseconds),
    };          
    _do_start(ts);
}

}
