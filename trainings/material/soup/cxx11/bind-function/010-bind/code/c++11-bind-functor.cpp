#include <functional>
#include <gtest/gtest.h>

class Functor
{
public:
    Functor(int i) : _i{i} {}
    int operator()(int addend)
    {
        return _i + addend;
    }

private:
    int _i;
};


TEST(bind_suite, functor)
{
    Functor func{42};
    auto funcfunc = std::bind(func, 1);
    ASSERT_EQ(funcfunc(), 43);
}
