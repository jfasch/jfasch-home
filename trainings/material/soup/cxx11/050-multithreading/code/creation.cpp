#include <gtest/gtest.h>

#include <thread>
#include <functional>


using namespace std;


static void f()
{
    // do something important
}

TEST(thread_creation_suite, plain_function_noargs)
{
    thread th(f);
    th.join();
}

static void g(int a, int b)
{
    // do something important
}

TEST(thread_creation_suite, plain_function_args)
{
    thread th(g, 1, 2);
    th.join();
}

static function<void(int, int)> fun_g = g;

TEST(thread_creation_suite, function)
{
    thread th(fun_g, 1, 2);
    th.join();
}

TEST(thread_creation_suite, lambda)
{
    int a = 1, b = 2;
    thread th([a, b](){});
    th.join();
}
