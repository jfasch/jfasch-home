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

class TimerList
{
private:
    struct timer
    {
        timerid hal_id;
        timer_t posix_id;
        timercb cb;
        void* context;
    };

public:
    timerid start_oneshot_timer_ms(unsigned long ms, timercb cb, void* context)
    {
        std::lock_guard<std::mutex> guard(_lock);

        timer* t = new timer;
        _timers.push_back(t);

        t->hal_id = _last_id++;
        t->cb = cb;
        t->context = context;

        sigevent ev;
        memset(&ev, 0, sizeof(ev));
        ev.sigev_notify = SIGEV_THREAD;
        ev.sigev_notify_function = timer_expired;
        ev.sigev_value.sival_ptr = t;

        timer_t posix_id;    

        int error = timer_create(CLOCK_MONOTONIC, &ev, &posix_id);
        assert(!error);

        t->posix_id = posix_id;

        itimerspec ts = {
            {0,0}, // interval (none; this is a one-shot timer)
            ms_to_timespec(ms),
        };          

        error = timer_settime(posix_id, 0, &ts, nullptr);
        assert(!error);

        return t->hal_id;
    }
    void stop_timer(timerid id)
    {
        std::lock_guard<std::mutex> guard(_lock);

        for (auto iter = _timers.begin(); iter != _timers.end(); ++iter) {
            const timer* t = *iter;
            if (t->hal_id == id) {
                int error = timer_delete(t->posix_id);  assert(!error);
                delete t;
                _timers.erase(iter);
                break;
            }
        }
    }

    size_t num_active_timers() const
    {
        std::lock_guard<std::mutex> guard(_lock);
        return _timers.size();
    }

    void reset()
    {
        _last_id = 0;
        assert(_timers.size() == 0);
    }

    static TimerList& instance()
    {
        return _instance;
    }

private:
    // called from glibc's timer callback
    static void timer_expired(union sigval v)
    {
        const timer* expired = (const timer*)v.sival_ptr;
        _instance.timer_expired(expired);
    }

    void timer_expired(const timer* expired)
    {
        timer_t posix_id = expired->posix_id;
        timercb cb = expired->cb;
        void* context = expired->context;

        {
            std::lock_guard<std::mutex> guard(_lock);

            // remove and delete my own timer structure
            for (auto iter = _timers.begin(); iter != _timers.end(); ++iter)
                if (*iter == expired) {
                    _timers.erase(iter);
                    break;
                }
        }

        delete expired;

        // delete posix timer
        int error = timer_delete(posix_id); assert(!error);

        cb(context);  // call out to user

    }

private:
    static timespec ms_to_timespec(unsigned long ms)
    {
        static const long ONE_SECOND_NS = 1000*1000*1000;
        long nanos = 1000*1000*ms;
        time_t secs = nanos / ONE_SECOND_NS;
        nanos %= ONE_SECOND_NS;

        return { secs, nanos };
    }

private:
    timerid _last_id = 0;

    using timerlist = std::vector<timer*>;
    mutable std::mutex _lock;
    timerlist _timers;

    static TimerList _instance;
};
TimerList TimerList::_instance;

size_t num_active_timers()
{
    return TimerList::instance().num_active_timers();
}


timerid start_oneshot_timer_ms(unsigned long ms, timercb cb, void* context)
{
    assert(is_initialized());

    return TimerList::instance().start_oneshot_timer_ms(ms, cb, context);
}

void stop_timer(timerid id)
{
    TimerList::instance().stop_timer(id);
}

timerid start_periodic_timer_ms(unsigned long interval_ms, timercb, void* context, size_t num_expiries)
{
    return 0;
}

namespace internal
{
void timers_init()
{
    TimerList::instance().reset();
}
void timers_deinit()
{
    assert(TimerList::instance().num_active_timers() == 0);
    TimerList::instance().reset();
}

} // /internal

}
