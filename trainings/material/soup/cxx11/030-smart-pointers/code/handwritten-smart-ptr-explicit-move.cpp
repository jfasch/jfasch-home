#include "sensors.h"
#include <gtest/gtest.h>

template <typename T> class SmartPtr
{
public:
    SmartPtr() : _p(nullptr) {}
    SmartPtr(T* p) : _p(p) {}
    ~SmartPtr() { delete _p; }

    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator=(const SmartPtr&) = delete;

    T* operator->() { return _p; }
    const T* operator->() const { return _p; }
    T& operator*() { return *_p; }
    const T& operator*() const { return *_p; }

    const T* get() const { return _p; }

    void move(SmartPtr& other)
    {
        delete _p;
        _p = other._p;
        other._p = nullptr;
    }

private:
    T* _p;
};

TEST(handwritten_suite, explicit_move)
{
    SmartPtr<Sensor> s1{new ConstantSensor{20}};
    SmartPtr<Sensor> s2;
    
    s2.move(s1);

    ASSERT_EQ(s1.get(), nullptr);
    ASSERT_DOUBLE_EQ(s2->get_temperature(), 20);
}
