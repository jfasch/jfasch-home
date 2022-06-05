#include <gtest/gtest.h>

class Integer
{
public:
    Integer(int i) : _i{i} {}

    void add_to_yourself_and_guarantee_programmers_job_security(int addend)
    {
        auto f = [this, addend](){
            _i += addend;     // <--- access _i as-if lambda were a class method
        };
        f();
    }

    operator int() const { return _i; }

private:
    int _i;
};

TEST(lambda_capure_suite, this_capture)
{
    Integer i{42};
    i.add_to_yourself_and_guarantee_programmers_job_security(7);
    ASSERT_EQ(i, 49);
}
