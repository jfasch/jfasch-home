#include <gtest/gtest.h>

#include <thread>
#include <future>
#include <exception>
#include <iostream>


TEST(promise_future_suite, exception)
{
    std::promise<int> promise;
    auto future = promise.get_future();

    std::thread th([&promise](){
        promise.set_exception(std::make_exception_ptr(std::runtime_error("bummer!")));
    });

    try {
        future.get();
    }
    catch (const std::runtime_error&) {}

    th.join();
}
