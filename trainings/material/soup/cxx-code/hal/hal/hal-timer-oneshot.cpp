#include "hal-timer-oneshot.h"

#include "hal-util.h"


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
    _is_active = true;
    _do_start(ts);
}

void OneshotTimer::stop()
{
    _is_active = false;
    _do_stop();
}

void OneshotTimer::_expired()
{
    _is_active = false; // disarmed by system at expiry
    _call_user();
}

}
