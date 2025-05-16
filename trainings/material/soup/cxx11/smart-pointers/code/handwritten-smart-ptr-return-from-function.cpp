#include "sensors.h"
#include <gtest/gtest.h>

template <typename T> class SmartPtr
{
public:
    SmartPtr() : _p(nullptr) {}
    SmartPtr(T* p) : _p(p) {}
    ~SmartPtr() { delete _p; }

    SmartPtr(SmartPtr&& from)
    {
        delete _p;

        // think about atomic-exchange though, maybe
        _p = from._p;
        from._p = nullptr;
    }

    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator=(const SmartPtr&) = delete;

    T* operator->() { return _p; }
    const T* operator->() const { return _p; }
    T& operator*() { return *_p; }
    const T& operator*() const { return *_p; }

    const T* get() const { return _p; }

private:
    T* _p;
};


SmartPtr<Sensor> create_constant_sensor(double temperature)
{
    SmartPtr<Sensor> sp{new ConstantSensor{36.5}};
    return sp;
}

TEST(handwritten_suite, return_by_copy)
{
    auto a_sensor = create_constant_sensor(36.5);
    ASSERT_FLOAT_EQ(a_sensor->get_temperature(), 36.5);
}
