#include <thread>
#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

static const auto TEN_MILLION_YEARS = 2s;
static const auto ANSWER_POLL_INTERVAL = 2ms;

int main()
{
    int answer;
    bool answer_valid;

    std::thread chew_answer([&answer, &answer_valid]() {
        // chew on world until we know the answer
        std::this_thread::sleep_for(TEN_MILLION_YEARS);

        answer = 42;
        answer_valid = true;
    });
    
    while (! answer_valid)
        std::this_thread::sleep_for(ANSWER_POLL_INTERVAL);
    std::cout << answer << std::endl;

    chew_answer.join();
    return 0;
}
