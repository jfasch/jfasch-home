#include <coroutine>
#include <iostream>

class Coro {
public:
    struct promise_type
    {
        Coro get_return_object() { return Coro(this); }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept(true) { return {}; }
        void return_void() {}        
        void unhandled_exception() {}
    };
    using Handle = std::coroutine_handle<promise_type>;

public:
    Coro(promise_type* p) : _coro(Handle::from_promise(*p)) {}
    void resume() { _coro.resume(); }

private:
    Handle _coro;
};

Coro hello()
{
    std::cout << "Hello" << std::endl;
    co_return;
}

int main()
{
    auto hello_instance = hello();
    hello_instance.resume();
    return 0;
}
