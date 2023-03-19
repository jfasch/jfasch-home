#pragma once

#include <signal.h>
#include <time.h>
#include <unistd.h>


namespace jf::hal
{

class Timer
{
public:
    class User
    {
    public:
        virtual ~User() {}
        virtual void expired() = 0;
    };

public:
    Timer(User*);
    virtual ~Timer();

    virtual void start() = 0;
    void stop();

    bool is_active() const { return _is_active; }

public:
    void call() const 
    {
        _user->expired();
    }

    // for testing only!
    timer_t id() const { return _id; }

protected:
    void _do_start(itimerspec);

    // callback function for timer_create()
    static void _timer_expired(union sigval);

private:
    User* _user;
    timer_t _id;
    bool _is_active;

public:
    static timespec ms_to_timespec(unsigned long ms)
    {
        static const long ONE_SECOND_NS = 1000*1000*1000;
        long nanos = 1000*1000*ms;
        time_t secs = nanos / ONE_SECOND_NS;
        nanos %= ONE_SECOND_NS;

        return { secs, nanos };
    }
};

}
