#include <thread>
#include <future>
#include <iostream>
#include <chrono>
#include <exception>

using namespace std::literals::chrono_literals;

static const auto TEN_MILLION_YEARS = 2s;


int main()
{
    std::promise<int> answer_promise;
    auto answer_future = answer_promise.get_future();

    std::thread chew_answer([&answer_promise]() {
        // chew on world until we know the answer
        std::this_thread::sleep_for(TEN_MILLION_YEARS);
        answer_promise.set_exception(std::make_exception_ptr(std::runtime_error("bummer!")));
    });

    try {
        answer_future.get();
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    chew_answer.join();
    return 0;
}
