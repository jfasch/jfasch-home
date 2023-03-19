#include "hal-timer.h"

#include <string.h>
#include <assert.h>


namespace jf::hal
{

Timer::Timer(User* u)
: _user(u)
{
    sigevent ev;
    memset(&ev, 0, sizeof(ev));
    ev.sigev_notify = SIGEV_THREAD;
    ev.sigev_notify_function = _expired;
    ev.sigev_value.sival_ptr = this;

    int error = timer_create(CLOCK_MONOTONIC, &ev, &_id);
    assert(!error);
}

Timer::~Timer()
{
    int error = timer_delete(_id);
    assert(!error);
}

void Timer::_do_start(itimerspec s)
{
    int error = timer_settime(_id, 0, &s, nullptr);
    assert(!error);
}

void Timer::_do_stop()
{
    itimerspec s = {{},{}};
    int error = timer_settime(_id, 0, &s, nullptr);
    assert(!error);
}

void Timer::_expired(union sigval v)
{
    Timer* t = (Timer*)v.sival_ptr;
    t->_expired();
}

}
