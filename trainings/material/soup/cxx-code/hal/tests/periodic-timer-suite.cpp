#include "hal-init.h"

#include <hal-timer.h>

#include <gtest/gtest.h>

#include <time.h>
#include <cassert>


struct periodic_timer_suite : HAL_Fixture {};


static void timer_expired_flag(void* context)
{
    size_t* expire_count = (size_t*)context;
    ++expire_count;
}

TEST_F(periodic_timer_suite, basic_expiry)
{
    FAIL();

    size_t expire_count = 0;
    
    jf::hal::start_periodic_timer_ms(1, timer_expired_flag, &expire_count, 7);

    timespec delay = {0/*s*/, 1000*1000/*ns, =1ms*/};

    while (expire_count != 7) {
        int error = nanosleep(&delay, nullptr);
        assert(!error);
        (void)error;
    }

    ASSERT_EQ(jf::hal::num_active_timers(), 0);
}

TEST_F(periodic_timer_suite, infinite_expiries)
{
    FAIL();
}
