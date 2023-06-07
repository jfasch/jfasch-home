#include <coroutine>
#include <iostream>
#include <vector>

class Cycle
{
public:
    class promise_type
    {
    public: // customization of coro behavior
        Cycle get_return_object() { return Cycle(this); }
        std::suspend_never initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        std::suspend_always yield_value(int elem)
        {
            _elem = elem;
            return {};
        }
        void unhandled_exception() {}

    public:
        int elem() const { return _elem; }
    private:
        int _elem{666};
    };

    using Handle = std::coroutine_handle<promise_type>;

public:
    explicit Cycle(promise_type* p) : _coro(Handle::from_promise(*p)) {}
    ~Cycle()
    { 
        if (_coro)
            _coro.destroy();
    }

    int next() const { return _coro.promise().elem(); }
    void resume() { _coro.resume(); }

private:
    Handle _coro{};
};

Cycle cycle(const std::vector<int>& elems)
{
    auto the_elems = elems;
    while (true)
        for (const auto& e: the_elems)
            co_yield e;
}

int main()
{
    auto c = cycle({1,2,3,4});

    for (;;) {
        std::cout << c.next() << std::endl;
        c.resume();
    }

    return 0;
}
