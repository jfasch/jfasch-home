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
    virtual void stop() = 0;

    virtual bool is_active() const = 0;

public:
    // for testing only!
    timer_t id() const { return _id; }

protected:
    void _do_start(itimerspec);
    void _do_stop();

    // callback function for timer_create()
    static void _expired(union sigval);
    virtual void _expired() = 0; // called by static counterpart

    void _call_user()
    {
        _user->expired();
    }

private:
    User* _user;
    timer_t _id;
};

}
