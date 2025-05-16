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
        _p = from._p;
        from._p = nullptr;
    }

    SmartPtr& operator=(SmartPtr&& from)
    {
        // much like self-assignment check, but more dubious
        if (this != &from) {
            delete _p;
            _p = from._p;
            from._p = nullptr;
        }
        return *this;
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



TEST(handwritten_suite, assignment)
{
    SmartPtr<Sensor> a_sensor{new ConstantSensor{36.5}};
    SmartPtr<Sensor> another_sensor;
    another_sensor = std::move(a_sensor);
    ASSERT_EQ(a_sensor.get(), nullptr);
}
