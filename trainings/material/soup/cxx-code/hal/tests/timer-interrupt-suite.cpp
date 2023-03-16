#include "hal-init.h"

#include <timer-interrupt.h>

#include <gtest/gtest.h>

#include <time.h>
#include <cassert>


struct timer_interrupt_suite : HAL_Fixture {};


void timer_expired(void* context)
{
    bool* expired_flag = (bool*)context;
    *expired_flag = true;
}

TEST_F(timer_interrupt_suite, basic)
{
    bool expired = false;
    jf::hal::start_timer_ms(1, timer_expired, &expired);

    timespec delay = {0/*s*/, 1000*1000/*ns, =1ms*/};

    unsigned nwaits = 1000;
    while (!expired) {
        int error = nanosleep(&delay, nullptr);
        assert(!error);
        (void)error;
        if (--nwaits == 0)
            FAIL();
    }
}
