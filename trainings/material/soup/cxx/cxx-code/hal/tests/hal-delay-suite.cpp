#include <gtest/gtest.h>

#include <hal.h>


TEST(delay_suite, basic)
{
    jf::hal::delay_ms(5);
}
