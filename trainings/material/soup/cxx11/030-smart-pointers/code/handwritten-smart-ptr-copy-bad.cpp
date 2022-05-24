#include "sensors.h"
#include <gtest/gtest.h>

template <typename T> class SmartPtr
{
public:
    SmartPtr() : _p(nullptr) {}
    SmartPtr(T* p) : _p(p) {}
    ~SmartPtr() { delete _p; }

    T* operator->() { return _p; }
    const T* operator->() const { return _p; }
    T& operator*() { return *_p; }
    const T& operator*() const { return *_p; }

private:
    T* _p;
};

TEST(handwritten_suite, copy_ctor_bad)
{
    SmartPtr<Sensor> s1{new ConstantSensor{20}};
    SmartPtr<Sensor> s2{s1};

    ASSERT_EQ(s1->get_temperature(), 20);
    ASSERT_EQ(s2->get_temperature(), 20);
}

TEST(handwritten_suite, assignment_operator_bad)
{
    SmartPtr<Sensor> s1{new ConstantSensor{20}};
    SmartPtr<Sensor> s2;
    
    s2 = s1;

    ASSERT_EQ(s1->get_temperature(), 20);
    ASSERT_EQ(s2->get_temperature(), 20);
}
