#include "hal-timer-oo.h"

#include <string.h>
#include <assert.h>


namespace jf::hal
{

static timespec ms_to_timespec(unsigned long ms)
{
    static const long ONE_SECOND_NS = 1000*1000*1000;
    long nanos = 1000*1000*ms;
    time_t secs = nanos / ONE_SECOND_NS;
    nanos %= ONE_SECOND_NS;

    return { secs, nanos };
}

OneshotTimer::OneshotTimer(size_t milliseconds, User* u)
: _milliseconds(milliseconds),
  _user(u)
{
    sigevent ev;
    memset(&ev, 0, sizeof(ev));
    ev.sigev_notify = SIGEV_THREAD;
    ev.sigev_notify_function = timer_expired;
    ev.sigev_value.sival_ptr = this;

    int error = timer_create(CLOCK_MONOTONIC, &ev, &_id);
    assert(!error);
}

OneshotTimer::~OneshotTimer()
{
    int error = timer_delete(_id);
    assert(!error);
}

void OneshotTimer::start()
{
    itimerspec ts = {
        {0,0}, // interval (none; this is a one-shot timer)
        ms_to_timespec(_milliseconds),
    };          

    int error = timer_settime(_id, 0, &ts, nullptr);
    assert(!error);

    _is_active = true;
}

void OneshotTimer::stop()
{
    itimerspec s = {{},{}};
    int error = timer_settime(_id, 0, &s, nullptr);
    assert(!error);

    _is_active = false;
}

void OneshotTimer::timer_expired(union sigval v)
{
    OneshotTimer* expired = (OneshotTimer*)v.sival_ptr;
    expired->_is_active = false;
    expired->call();
}

}
