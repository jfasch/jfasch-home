#include "hal-timer.h"

#include "hal-core.h"

#include <vector>
#include <mutex>

#include <assert.h>
#include <string.h>
#include <signal.h>
#include <time.h>


namespace jf::hal
{

static timerid last_id = 0;
struct timer
{
    timerid hal_id;
    timer_t posix_id;
    timercb cb;
    void* context;
};
using timerlist = std::vector<timer*>;

static std::mutex timers_mutex;
static timerlist timers;

static void timer_trampoline(union sigval v)
{
    const timer* expired = (const timer*)v.sival_ptr;

    timer_t posix_id = expired->posix_id;
    timercb cb = expired->cb;
    void* context = expired->context;

    {
        std::lock_guard<std::mutex> guard(timers_mutex);

        // remove and delete my own timer structure
        for (auto iter = timers.begin(); iter != timers.end(); ++iter)
            if (*iter == expired) {
                timers.erase(iter);
                break;
            }
    }

    delete expired;

    // delete posix timer
    int error = timer_delete(posix_id); assert(!error);

    cb(context);  // call out to user
}

size_t num_active_timers()
{
    std::lock_guard<std::mutex> guard(timers_mutex);
    return timers.size();
}

timerid start_oneshot_timer_ms(unsigned long ms, timercb cb, void* context)
{
    assert(is_initialized());

    std::lock_guard<std::mutex> guard(timers_mutex);

    timer* t = new timer;
    timers.push_back(t);

    t->hal_id = last_id++;
    t->cb = cb;
    t->context = context;

    sigevent ev;
    memset(&ev, 0, sizeof(ev));
    ev.sigev_notify = SIGEV_THREAD;
    ev.sigev_notify_function = timer_trampoline;
    ev.sigev_value.sival_ptr = t;

    timer_t posix_id;    

    int error = timer_create(CLOCK_MONOTONIC, &ev, &posix_id);
    assert(!error);

    t->posix_id = posix_id;

    static const long ONE_SECOND_NS = 1000*1000*1000;
    long nanos = 1000*1000*ms;
    time_t secs = nanos / ONE_SECOND_NS;
    nanos %= ONE_SECOND_NS;
    
    itimerspec ts = {
        {0,0}, // interval (none; this is a one-shot timer)
        { secs, nanos },
    };          

    error = timer_settime(posix_id, 0, &ts, nullptr);
    assert(!error);

    return t->hal_id;
}

void stop_timer(timerid id)
{
    std::lock_guard<std::mutex> guard(timers_mutex);

    for (auto iter = timers.begin(); iter != timers.end(); ++iter) {
        const timer* t = *iter;
        if (t->hal_id == id) {
            int error = timer_delete(t->posix_id);  assert(!error);
            delete t;
            timers.erase(iter);
            break;
        }
    }
}

namespace internal
{
void timers_init()
{
    last_id = 0;
}
void timers_deinit()
{
    assert(timers.size() == 0);
}

} // /internal

}
