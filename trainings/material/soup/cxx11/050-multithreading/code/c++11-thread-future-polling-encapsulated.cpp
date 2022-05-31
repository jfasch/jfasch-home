#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

static const auto TEN_MILLION_YEARS = 2s;
static const auto ANSWER_POLL_INTERVAL = 2ms;


class Answer
{
public:
    Answer() : _answer_valid(false) {}
    
    void set(int answer)
    {
        std::scoped_lock guard(_lock);
        _answer = answer;
        _answer_valid = true;
    }

    template <typename dur>
    int wait(dur d)
    {
        while (true) {
            std::scoped_lock guard(_lock);
            if (_answer_valid)
                return _answer;
            std::this_thread::sleep_for(d);
        }
    }

private:
    std::mutex _lock;
    int _answer;
    bool _answer_valid;
};

int main()
{
    Answer answer;

    std::thread chew_answer([&answer]() {
        // chew on world until we know the answer
        std::this_thread::sleep_for(TEN_MILLION_YEARS);
        answer.set(42);
    });

    std::cout << answer.wait(ANSWER_POLL_INTERVAL) << std::endl;

    chew_answer.join();
    return 0;
}
