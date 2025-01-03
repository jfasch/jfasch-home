#include <hal.h>

#include <gtest/gtest.h>

#include <time.h>
#include <cassert>


class MyTimerUser : public jf::hal::Timer::User
{
public:
    MyTimerUser() : _n_expiries(0) {}

    void expired() override { _n_expiries++; }
    size_t n_expiries() const { return _n_expiries; }

private:
    size_t _n_expiries;
};

TEST(periodic_timer_suite, basic_expiry)
{
    MyTimerUser u;
    jf::hal::PeriodicTimer timer(1/*ms*/, &u);
    timer.start();

    ASSERT_TRUE(timer.is_active());

    timespec delay = {0/*s*/, 1000*1000/*ns, =1ms*/};

    unsigned nwaits = 1000;
    while (u.n_expiries() < 700) {
        int error = nanosleep(&delay, nullptr);
        assert(!error);
        (void)error;
        if (--nwaits == 0)
            FAIL();
    }

    ASSERT_TRUE(timer.is_active());
}

TEST(periodic_timer_suite, stop_before_expiry)
{
    MyTimerUser u;
    jf::hal::PeriodicTimer timer(
        1000*1000,     // enough time to stop timer before it expires
        &u);
    timer.start();

    ASSERT_TRUE(timer.is_active());
    timer.stop();
    ASSERT_FALSE(timer.is_active());
}

TEST(periodic_timer_suite, dtor_cleanup)
{
    timer_t id;
    {
        MyTimerUser u;
        jf::hal::PeriodicTimer timer(
            1000*1000,     // enough time to stop timer before it expires
            &u);
        timer.start();

        id = timer.id();
    }    // <--- dtor called here

    itimerspec s = {{},{}};
    int error = timer_settime(id, 0, &s, nullptr);
    ASSERT_TRUE(error);
    ASSERT_EQ(errno, EINVAL);
}
