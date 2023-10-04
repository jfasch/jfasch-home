#include <gtest/gtest.h>

#include <switch-mock-nopoly.h>
#include <sensor-mock-nopoly.h>
#include <display-led-stripe-nopoly.h>

#include <vector>

TEST(display_led_stripe_nopoly_suite, above_range)
{
    MockSensor_nopoly sensor(100);                     // <--- below [0,80]
    MockSwitch_nopoly sw0(MockSwitch_nopoly::OFF);
    MockSwitch_nopoly sw1(MockSwitch_nopoly::OFF);
    MockSwitch_nopoly sw2(MockSwitch_nopoly::OFF);
    MockSwitch_nopoly sw3(MockSwitch_nopoly::OFF);
    MockSwitch_nopoly sw4(MockSwitch_nopoly::OFF);
    MockSwitch_nopoly sw5(MockSwitch_nopoly::OFF);
    MockSwitch_nopoly sw6(MockSwitch_nopoly::OFF);
    MockSwitch_nopoly sw7(MockSwitch_nopoly::OFF);

    std::vector<MockSwitch_nopoly*> switches = { &sw0, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7 };
    LEDStripeDisplay_nopoly display(
        0, 80,                                         // <--- [0,80]
        &sensor, switches);

    display.check();

    ASSERT_EQ(sw0.state(), MockSwitch_nopoly::ON);
    ASSERT_EQ(sw1.state(), MockSwitch_nopoly::ON);
    ASSERT_EQ(sw2.state(), MockSwitch_nopoly::ON);
    ASSERT_EQ(sw3.state(), MockSwitch_nopoly::ON);
    ASSERT_EQ(sw4.state(), MockSwitch_nopoly::ON);
    ASSERT_EQ(sw5.state(), MockSwitch_nopoly::ON);
    ASSERT_EQ(sw6.state(), MockSwitch_nopoly::ON);
    ASSERT_EQ(sw7.state(), MockSwitch_nopoly::ON);
}
