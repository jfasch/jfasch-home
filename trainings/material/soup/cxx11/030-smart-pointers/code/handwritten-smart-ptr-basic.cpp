#include "sensors.h"
#include <gtest/gtest.h>

template <typename T> class SmartPtr
{
public:
    SmartPtr(T* p) : _p(p) {}
    ~SmartPtr() { delete _p; }

    T* operator->() { return _p; }
    const T* operator->() const { return _p; }
    T& operator*() { return *_p; }
    const T& operator*() const { return *_p; }

private:
    T* _p;
};

TEST(handwritten_suite, basic)
{
    SmartPtr<Sensor> s{new ConstantSensor{20}};

    ASSERT_EQ(s->get_temperature(), 20);
    ASSERT_EQ((*s).get_temperature(), 20);
}

TEST(handwritten_suite, basic_const)
{
    const SmartPtr<Sensor> s{new ConstantSensor{20}};

    const Sensor* raw_s = s.operator->();
    const Sensor& raw_s_ref = s.operator*();

    (void)raw_s;
    (void)raw_s_ref;
}
