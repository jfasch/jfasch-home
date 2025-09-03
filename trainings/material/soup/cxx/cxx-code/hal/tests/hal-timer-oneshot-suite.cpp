#include <hal.h>

#include <gtest/gtest.h>

#include <time.h>
#include <cassert>


class MyTimerUser : public jf::hal::Timer::User
{
public:
    MyTimerUser() : _expired(false) {}

    void expired() override { _expired = true; }
    bool is_expired() const { return _expired; }

private:
    bool _expired;
};

TEST(oneshot_timer_suite, basic_expiry)
{
    MyTimerUser u;
    jf::hal::OneshotTimer timer(1, &u);
    timer.start();

    ASSERT_TRUE(timer.is_active());

    timespec delay = {0/*s*/, 1000*1000/*ns, =1ms*/};

    unsigned nwaits = 1000;
    while (!u.is_expired()) {
        int error = nanosleep(&delay, nullptr);
        assert(!error);
        (void)error;
        if (--nwaits == 0)
            FAIL();
    }

    ASSERT_FALSE(timer.is_active());
}

TEST(oneshot_timer_suite, stop_before_expiry)
{
    MyTimerUser u;
    jf::hal::OneshotTimer timer(
        1000*1000,     // enough time to stop timer before it expires
        &u);
    timer.start();

    ASSERT_TRUE(timer.is_active());
    timer.stop();
    ASSERT_FALSE(timer.is_active());
}

TEST(oneshot_timer_suite, dtor_cleanup)
{
    timer_t id;
    {
        MyTimerUser u;
        jf::hal::OneshotTimer timer(
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
