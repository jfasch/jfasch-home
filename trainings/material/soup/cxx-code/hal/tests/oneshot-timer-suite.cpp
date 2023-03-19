#include "hal-init.h"

#include <hal-timer.h>

#include <gtest/gtest.h>

#include <time.h>
#include <cassert>


struct oneshot_timer_suite : HAL_Fixture {};


static void timer_expired_flag(void* context)
{
    bool* expired_flag = (bool*)context;
    *expired_flag = true;
}

TEST_F(oneshot_timer_suite, basic_expiry)
{
    bool expired = false;
    jf::hal::start_oneshot_timer_ms(1, timer_expired_flag, &expired);

    // this cannot be reliably checked: the timer might already have
    // expired ...
    
    // ASSERT_EQ(jf::hal::num_active_timers(), 0);

    timespec delay = {0/*s*/, 1000*1000/*ns, =1ms*/};

    unsigned nwaits = 1000;
    while (!expired) {
        int error = nanosleep(&delay, nullptr);
        assert(!error);
        (void)error;
        if (--nwaits == 0)
            FAIL();
    }

    ASSERT_EQ(jf::hal::num_active_timers(), 0);
}

TEST_F(oneshot_timer_suite, stop_before_expiry)
{
    bool flag;
    jf::hal::timerid id = jf::hal::start_oneshot_timer_ms(
        1000*1000,     // enough time to stop timer before it expires
        timer_expired_flag, &flag);
    ASSERT_EQ(jf::hal::num_active_timers(), 1);
    jf::hal::stop_timer(id);
    ASSERT_EQ(jf::hal::num_active_timers(), 0);
}
