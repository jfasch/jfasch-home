#include <coroutine>
#include <iostream>

struct Coro {
    struct promise_type
    {
        Coro get_return_object() { return {}; }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept(true) { return {}; }
        void return_void() {}        
        void unhandled_exception() {}
    };
};

Coro hello()
{
    std::cout << "Hello" << std::endl;
    co_return;
}

int main()
{
    auto hello_instance = hello();
    (void)hello_instance;
    return 0;
}
