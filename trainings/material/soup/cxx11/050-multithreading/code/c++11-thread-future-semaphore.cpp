#include <thread>
#include <semaphore>
#include <iostream>
#include <cassert>
#include <chrono>

using namespace std::literals::chrono_literals;

static constexpr auto TEN_MILLION_YEARS = 2s;


class Answer
{
public:
    Answer() : _notifier{0}
    {}
    
    void set(int answer)
    {
        _answer = answer;
        _notifier.release();
    }

    int wait()
    {
        _notifier.acquire();
        return _answer;
    }

private:
    std::binary_semaphore _notifier;
    int _answer;
};

int main()
{
    Answer answer;

    std::thread chew_answer([&answer]() {
        // chew on world until we know the answer
        std::this_thread::sleep_for(TEN_MILLION_YEARS);
        answer.set(42);
    });

    std::cout << answer.wait() << std::endl;

    chew_answer.join();
    return 0;
}
