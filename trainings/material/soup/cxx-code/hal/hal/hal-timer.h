#pragma once

#include <unistd.h>


namespace jf::hal
{

using timerid = size_t;
typedef void (*timercb)(void*);

size_t num_active_timers();
timerid start_oneshot_timer_ms(unsigned long ms, timercb, void* context);
void stop_timer(timerid);

namespace internal
{
void timers_init();
void timers_deinit();
}

}
