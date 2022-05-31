#include <thread>
#include <atomic>
#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

static const auto TEN_MILLION_YEARS = 2s;
static const auto ANSWER_POLL_INTERVAL = 2ms;


class Answer
{
public:
    void set(int answer)
    {
        _data = data(answer);
    }

    template <typename dur>
    int wait(dur d)
    {
        while (true) {
            data data = _data;
            if (data.answer_valid)
                return data.answer;
            std::this_thread::sleep_for(d);
        }
    }

private:
    struct data
    {
        data() : answer_valid(false) {}
        data(int answer) : answer_valid(true), answer(answer) {}
        bool answer_valid;
        int answer;
    };

    std::atomic<data> _data;
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
