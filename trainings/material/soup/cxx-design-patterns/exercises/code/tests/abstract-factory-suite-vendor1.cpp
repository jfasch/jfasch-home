#include <gtest/gtest.h>

#include <sensor-i2c-factory-vendor1.h>
#include <sensor-i2c-vendor1.h>


TEST(abstract_factory_suite, instantiate_vendor1)
{
    I2CSensorFactory_Vendor1 i2c_factory_vendor1;
    I2CSensorFactory* factory = &i2c_factory_vendor1;                      // <--- is-a I2CSensorFactory

    I2CSensor* i2c_sensor = factory->create(/*bus*/ 1, /*address*/ 0x37);  // <--- returns an I2CSensor
    ASSERT_EQ(i2c_sensor->bus(), 1);
    ASSERT_EQ(i2c_sensor->address(), 0x37);

    ASSERT_TRUE(dynamic_cast<I2CSensor_Vendor1*>(i2c_sensor));             // <--- ... from Vendor1

    Sensor* a_sensor = i2c_sensor;                                         // <--- and is-a (of course) Sensor

    // ... use sensor here ...

    delete a_sensor;                                                       // <--- *interface* dtor called usually, at program termination
}
