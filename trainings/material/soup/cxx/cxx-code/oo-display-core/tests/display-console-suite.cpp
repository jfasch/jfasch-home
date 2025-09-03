#include <display-console.h>

#include <gtest/gtest.h>


struct display_console_suite : public::testing::Test
{
    std::ostringstream output;
    void reset() { output = std::ostringstream(); }
};


TEST_F(display_console_suite, within_range)
{
    ConsoleDisplay display(10,      // num chars
                           '*',     // mark
                           ' ',     // space
                           0,       // min range
                           100,     // max range
                           0,       // center
                           output);

    display.show_temperature(0);
    ASSERT_EQ(output.str(), "*         ");    // <--- 0 is in [0, 10)

    reset();
    display.show_temperature(37.4);
    ASSERT_EQ(output.str(), "****      ");    // <--- 37.4 is in [30, 40)

    reset();
    display.show_temperature(90);
    ASSERT_EQ(output.str(), "**********");    // <--- 90 is in [90, 100)
}

TEST_F(display_console_suite, out_of_range)
{
    ConsoleDisplay display(10,      // num chars
                           '*',     // mark
                           ' ',     // space
                           0,       // min range
                           100,     // max range
                           0,       // center
                           output);

    display.show_temperature(100);
    ASSERT_EQ(output.str(), "**********");    // <--- 100 overflows (the last valid interval is [90, 100) )

    reset();
    display.show_temperature(1000);
    ASSERT_EQ(output.str(), "**********");    // <--- 1000 overflows, obviously

    reset();
    display.show_temperature(-0.1);
    ASSERT_EQ(output.str(), "          ");    // <--- -0.1 underflows, obviously

    reset();
    display.show_temperature(-1000);
    ASSERT_EQ(output.str(), "          ");    // <--- -1000 underflows, obviously
}

TEST_F(display_console_suite, negative)
{
    ConsoleDisplay display(11, '*', ' ', -50, +50, 0, output);

    display.show_temperature(-50);
    ASSERT_EQ(output.str(), "******     ");

    reset();
    display.show_temperature(50);
    ASSERT_EQ(output.str(), "     ******");

    reset();
    display.show_temperature(0);
    ASSERT_EQ(output.str(), "     *     ");

    reset();
    display.show_temperature(10);
    ASSERT_EQ(output.str(), "     **    ");
}

TEST_F(display_console_suite, console_display__is_a__display)
{
    ConsoleDisplay console_display(10, '*', ' ', 0, 100, 0, output);
    Display* display = &console_display;        // <--- successful compilation passes test

    (void)display;
}
