#include "hal-timer-periodic.h"


namespace jf::hal
{

PeriodicTimer::PeriodicTimer(size_t milliseconds, User* u)
: Timer(u),
  _milliseconds(milliseconds) {}

void PeriodicTimer::start()
{
    itimerspec ts = {
        ms_to_timespec(_milliseconds),
        {0,1}, // first expiry (as soon as possible - i.e. in one nanosecond)
    };          
    _is_active = true;
    _do_start(ts);
}

void PeriodicTimer::stop()
{
    _is_active = false;
    _do_stop();
}

void PeriodicTimer::_expired()
{
    _call_user();
}

}
