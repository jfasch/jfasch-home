#pragma once

#include <signal.h>
#include <time.h>
#include <unistd.h>


namespace jf::hal
{

class OneshotTimer
{
public:
    class User
    {
    public:
        virtual ~User() {}
        virtual void expired() = 0;
    };

public:
    OneshotTimer(size_t milliseconds, User*);
    ~OneshotTimer();

    void start();
    void stop();

    bool is_active() const { return _is_active; }

public:
    void call() const 
    {
        _user->expired();
    }

    // for testing only!
    timer_t id() const { return _id; }

private:
    size_t _milliseconds;
    User* _user;
    timer_t _id;
    bool _is_active = false;

private:
    // callback function for timer_create()
    static void timer_expired(union sigval);
};

}
