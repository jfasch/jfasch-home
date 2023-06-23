#include <gtest/gtest.h>

#include <switch-mock-nopoly.h>
#include <sensor-mock-nopoly.h>
#include <display-led-stripe-nopoly.h>

#include <vector>

TEST(display_led_stripe_nopoly_suite, variation_2_switches)
{
    MockSensor_nopoly sensor(36.5);                    // <--- right in the middle of [0,80]
    MockSwitch_nopoly sw0(MockSwitch_nopoly::OFF);
    MockSwitch_nopoly sw1(MockSwitch_nopoly::OFF);

    std::vector<MockSwitch_nopoly*> switches = { &sw0, &sw1 };
    LEDStripeDisplay_nopoly display(
        0, 80,                                         // <--- [0,80]
        &sensor, switches);

    display.check();

    ASSERT_EQ(sw0.state(), MockSwitch_nopoly::ON);
    ASSERT_EQ(sw1.state(), MockSwitch_nopoly::OFF);
}

TEST(display_led_stripe_nopoly_suite, variation_interval_not_from_0)
{
    MockSensor_nopoly sensor(10.7);                    // <--- right above low
    MockSwitch_nopoly sw0(MockSwitch_nopoly::OFF);
    MockSwitch_nopoly sw1(MockSwitch_nopoly::OFF);

    std::vector<MockSwitch_nopoly*> switches = { &sw0, &sw1 };
    LEDStripeDisplay_nopoly display(
        10.5, 80,                                      // <--- [10.5,80]
        &sensor, switches);

    display.check();

    ASSERT_EQ(sw0.state(), MockSwitch_nopoly::ON);
    ASSERT_EQ(sw1.state(), MockSwitch_nopoly::OFF);

    sensor.set_temperature(45.7);                      // <--- into second LED

    display.check();

    ASSERT_EQ(sw0.state(), MockSwitch_nopoly::ON);
    ASSERT_EQ(sw1.state(), MockSwitch_nopoly::ON);
}
