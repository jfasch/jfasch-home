#include <thread>
#include <iostream>
#include <cassert>
#include <time.h>


static const unsigned TEN_MILLION_YEARS_S = 2;
static const unsigned ANSWER_POLL_INTERVAL_MS = 2;

int main()
{
    int answer;
    bool answer_valid;

    std::thread chew_answer([&answer, &answer_valid]() {
        // chew on world until we know the answer
        timespec ts { TEN_MILLION_YEARS_S, 0 };
        int error = nanosleep(&ts, nullptr);
        assert(!error);

        answer = 42;
        answer_valid = true;
    });
    
    while (! answer_valid) {
        timespec ts { 0, ANSWER_POLL_INTERVAL_MS * 1000*1000 };  // assuming less than a second
        int error = nanosleep(&ts, nullptr);
        assert(!error);
    }
    std::cout << answer << std::endl;

    chew_answer.join();
    return 0;
}
