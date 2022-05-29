#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

static const auto TEN_MILLION_YEARS = 2s;
static const auto ANSWER_POLL_INTERVAL = 2ms;

int main()
{
    std::mutex lock;
    int answer;
    bool answer_valid;

    std::thread chew_answer([&answer, &answer_valid, &lock]() {
        // chew on world until we know the answer
        std::this_thread::sleep_for(TEN_MILLION_YEARS);

        lock.lock();
        answer = 42;
        answer_valid = true;
        lock.unlock();
    });

    bool done = false;
    while (! done) {
        lock.lock();
        if (answer_valid) {
            done = true;
            std::cout << answer << std::endl;
        }
        else
            std::this_thread::sleep_for(ANSWER_POLL_INTERVAL);
        lock.unlock();
    }

    chew_answer.join();
    return 0;
}
