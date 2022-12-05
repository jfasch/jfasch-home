#include <display-null.h>

#include <gtest/gtest.h>


TEST(display_null_suite, basic)
{
    NullDisplay display;

    display.show_temperature(37.4);

    double temp = display.current_temperature();    // <--- NullDisplay method
    ASSERT_FLOAT_EQ(temp, 37.4);
}

TEST(display_null_suite, initial_temperature)
{
    NullDisplay uninitialized_display;
    ASSERT_FLOAT_EQ(uninitialized_display.current_temperature(), 0.0);

    NullDisplay initialized_display(35.3);
    ASSERT_FLOAT_EQ(initialized_display.current_temperature(), 35.3);

    initialized_display.show_temperature(42.5);
    ASSERT_FLOAT_EQ(initialized_display.current_temperature(), 42.5);
}

TEST(display_null_suite, current_temperature__is_const)
{
    const NullDisplay null_display;
    ASSERT_FLOAT_EQ(null_display.current_temperature(), 0.0); // <--- successful compilation passes test
}

TEST(display_null_suite, is_a__display)
{
    NullDisplay null_display;
    Display* display = &null_display;        // <--- successful compilation passes test

    (void)display;
}
