#include <gtest/gtest.h>

TEST(lambda_capure_suite, explicit_by_copy)
{
    int x = 1, y = 2;

    auto fun = [x, y](){
        return x + y;
    };

    ASSERT_EQ(fun(), 3);

    x = 2;
    ASSERT_EQ(fun(), 3);
}

TEST(lambda_capure_suite, explicit_by_reference)
{
    int x = 1, y = 2;

    auto fun = [&x, &y](){
        return x + y;
    };

    ASSERT_EQ(fun(), 3);

    x = 2;
    ASSERT_EQ(fun(), 4);
}

TEST(lambda_capure_suite, explicit_mixed)
{
    int x = 1, y = 2;

    auto fun = [&x, y](){   // x by reference, y by copy
        return x + y;
    };

    ASSERT_EQ(fun(), 3);

    x = 2;
    ASSERT_EQ(fun(), 4);

    y = 3;
    ASSERT_EQ(fun(), 4);
}

TEST(lambda_capure_suite, initialized_capture)
{
    auto fun = [x=1, y=2](){
        return x + y;
    };

    ASSERT_EQ(fun(), 3);
}

TEST(lambda_capure_suite, all_by_reference)
{
    int x = 1, y = 2;

    auto fun = [&](){   // <-- all by reference
        return x + y;
    };

    ASSERT_EQ(fun(), 3);

    x = 2;
    ASSERT_EQ(fun(), 4);
}

TEST(lambda_capure_suite, all_by_copy)
{
    int x = 1, y = 2;

    auto fun = [=](){   // <-- all by reference
        return x + y;
    };

    ASSERT_EQ(fun(), 3);

    x = 2;
    ASSERT_EQ(fun(), 3);
}

TEST(lambda_capure_suite, all_by_copy_except)
{
    int x = 1, y = 2;

    auto fun = [=, &y](){   // <-- all by copy, except y by reference
        return x + y;
    };

    ASSERT_EQ(fun(), 3);

    x = 2;
    ASSERT_EQ(fun(), 3);

    y = 3;
    ASSERT_EQ(fun(), 4);
}

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
