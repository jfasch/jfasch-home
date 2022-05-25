#include "sensors.h"
#include <gtest/gtest.h>

template <typename T> class SmartPtr
{
public:
    SmartPtr() : _p(nullptr) {}
    SmartPtr(T* p) : _p(p) {}
    ~SmartPtr() { delete _p; }

    SmartPtr(SmartPtr& other)
    : _p(other._p)
    {
        other._p = nullptr;
    }
    SmartPtr& operator=(SmartPtr& other)
    {
        if (this != &other /*self assignment*/) {
            delete _p;
            _p = other._p;
            other._p = nullptr;
        }
        return *this;
    }

    T* operator->() { return _p; }
    const T* operator->() const { return _p; }
    T& operator*() { return *_p; }
    const T& operator*() const { return *_p; }

    const T* get() const { return _p; }

private:
    T* _p;
};

TEST(handwritten_suite, copy_ctor_good_autoptr_style)
{
    SmartPtr<Sensor> s1{new ConstantSensor{20}};
    SmartPtr<Sensor> s2{s1};

    // ASSERT_DOUBLE_EQ(s1->get_temperature(), 20);    // <---- CRASHES, UNEXPECTEDLY?
    ASSERT_EQ(s1.get(), nullptr);
    ASSERT_DOUBLE_EQ(s2->get_temperature(), 20);
}

TEST(handwritten_suite, assignment_operator_good_autoptr_style)
{
    SmartPtr<Sensor> s1{new ConstantSensor{20}};
    SmartPtr<Sensor> s2;
    
    s2 = s1;

    // ASSERT_DOUBLE_EQ(s1->get_temperature(), 20);    // <---- CRASHES, UNEXPECTEDLY?
    ASSERT_EQ(s1.get(), nullptr);
    ASSERT_DOUBLE_EQ(s2->get_temperature(), 20);
}
