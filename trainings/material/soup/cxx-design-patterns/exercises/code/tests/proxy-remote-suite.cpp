#include <gtest/gtest.h>

#include <server-thread.h>
#include <sensor-const.h>
#include <sensor-remote.h>
#include <sensor-remote-adapter.h>


struct proxy_remote_suite : ::testing::Test    // <--- fixture: server thread and sensor setup
{
    proxy_remote_suite()
    : _cs(42.0),
      _adapter(&_cs),
      server(&_adapter)
    {}

    ConstantSensor _cs;
    RemoteSensorAdapter _adapter;
    ServerThread server;
};

TEST_F(proxy_remote_suite, protocol)
{
    RemoteSensor rs(&server);
    ASSERT_FLOAT_EQ(rs.get_temperature(), 42.0);
}

TEST_F(proxy_remote_suite, remote_sensor__is_a__sensor)
{
    RemoteSensor rs(&server);
    Sensor* s = &rs;
    ASSERT_FLOAT_EQ(s->get_temperature(), 42.0);
}
