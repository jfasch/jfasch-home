#pragma once


namespace jf::hal
{

typedef void (*timercb)(void*);

void start_timer_ms(unsigned long ms, timercb, void* context);

}
