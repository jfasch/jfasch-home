#include "timer-interrupt.h"

#include "hal-core.h"

#include <assert.h>
#include <string.h>
#include <signal.h>
#include <time.h>


namespace jf::hal
{

struct timer
{
    timer_t id;            // POSIX timer id
    timercb cb;            // user callback
    void* context;         // user context
};

static void timer_trampoline(union sigval v)
{
    timer* t = (timer*)v.sival_ptr;

    timer_t id = t->id;
    timercb cb = t->cb;
    void* context = t->context;

    delete t;

    int error = timer_delete(id); assert(!error);
    cb(context);
}

void start_timer_ms(unsigned long ms, timercb cb, void* context)
{
    assert(is_initialized());

    timer* t = new timer;
    t->cb = cb;
    t->context = context;

    sigevent ev;
    memset(&ev, 0, sizeof(ev));
    ev.sigev_notify = SIGEV_THREAD;
    ev.sigev_notify_function = timer_trampoline;
    ev.sigev_value.sival_ptr = t;

    timer_t id;    

    int error = timer_create(CLOCK_MONOTONIC, &ev, &id);
    assert(!error);

    t->id = id;

    static const long ONE_SECOND_NS = 1000*1000*1000;
    long nanos = 1000*1000*ms;
    time_t secs = nanos / ONE_SECOND_NS;
    nanos %= ONE_SECOND_NS;
    
    itimerspec ts = {
        {0,0}, // interval (none; this is a one-shot timer)
        { secs, nanos },
    };          

    error = timer_settime(id, 0, &ts, nullptr);
    assert(!error);
}

}
