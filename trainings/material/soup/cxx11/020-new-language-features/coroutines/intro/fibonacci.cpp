#include <coroutine>
#include <iostream>
#include <cstdint>

class Fibonacci
{
public:
    class promise_type
    {
    public: // customization of coro behavior
        Fibonacci get_return_object() { return Fibonacci(this); }
        std::suspend_never initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        std::suspend_always yield_value(uint64_t elem)
        {
            _elem = elem;
            return {};
        }
        void unhandled_exception() {}

    public:
        uint64_t elem() const { return _elem; }
    private:
        uint64_t _elem{666};
    };

    using Handle = std::coroutine_handle<promise_type>;

public:
    explicit Fibonacci(promise_type* p) : _coro(Handle::from_promise(*p)) {}
    ~Fibonacci()
    { 
        if (_coro)
            _coro.destroy();
    }

    uint64_t next() const { return _coro.promise().elem(); }
    void resume() { _coro.resume(); }

private:
    Handle _coro{};
};

Fibonacci fibonacci()
{
    uint64_t first = 1;
    uint64_t second = 1;

    co_yield first;                                    // <--- suspend
    co_yield second;                                   // <--- suspend

    while (true) {
        uint64_t third = first + second;

        co_yield third;                                // <--- suspend
        
        first = second;
        second = third;
    }
}

int main()
{
    auto fibo = fibonacci();

    for (;;) {
        std::cout << fibo.next() << std::endl;
        fibo.resume();
    }

    return 0;
}
