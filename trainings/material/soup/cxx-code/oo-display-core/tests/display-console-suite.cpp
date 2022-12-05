#include <display-console.h>

#include <gtest/gtest.h>


struct display_console_suite : public::testing::Test
{
    std::ostringstream buffer;
    void reset() { buffer = std::ostringstream(); }
};


TEST_F(display_console_suite, basic)
{
    ConsoleDisplay display(10, '*', 0, 100, buffer);

    display.show_temperature(0);
    ASSERT_EQ(buffer.str(), "");

    reset();
    display.show_temperature(37.4);
    ASSERT_EQ(buffer.str(), "****");

    reset();
    display.show_temperature(90);
    ASSERT_EQ(buffer.str(), "*********");

    reset();
    display.show_temperature(100);
    ASSERT_EQ(buffer.str(), "**********");
}

TEST_F(display_console_suite, console_display__is_a__display)
{
    ConsoleDisplay console_display(10, '*', 0, 100, buffer);
    Display* display = &console_display;        // <--- successful compilation passes test

    (void)display;
}
