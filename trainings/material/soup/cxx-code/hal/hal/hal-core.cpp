#include "hal-core.h"

#include "hal-timer.h"

namespace jf::hal
{

static bool initialized;

void init()
{
    internal::timers_init();
    initialized = true;
}

void deinit()
{
    internal::timers_deinit();
    initialized = false;
}

bool is_initialized()
{
    return initialized;
}

}

