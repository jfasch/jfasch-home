#include "hal-core.h"

#include "timer-interrupt.h"

#include <queue.h>

#include <thread>


namespace jf::hal
{

static bool initialized;

void init()
{
    initialized = true;
}

void deinit()
{
    initialized = false;
}

bool is_initialized()
{
    return initialized;
}

}

