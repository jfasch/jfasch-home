#include <coroutine>
#include <iostream>

class Coro {
public:
    struct promise_type
    {
        Coro get_return_object() { return Coro(this); }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always yield_value(std::string v) // <--- called by co_yield  
        { 
            last_value = v;                            // <--- save yielded value
            return {};
        }
        std::suspend_always final_suspend() noexcept(true) { return {}; }
        void return_void() {}        
        void unhandled_exception() {}
        std::string last_value;                        // <--- last value co_yield'ed
    };

public:
    Coro(promise_type* p) : _promise(p) {}
    struct StopIteration {};                           // <--- Python-style sentinel exception
    std::string next()                                 // <--- produce next element, or throw StopIteration
    {
        auto coro = std::coroutine_handle<promise_type>::from_promise(*_promise);
        coro.resume();
        if (coro.done())
            throw StopIteration();
        return _promise->last_value;
    }

private:
    promise_type* _promise;
};

Coro hello()
{
    std::cout << "Saying Hello" << std::endl;
    co_yield "Hello";
    std::cout << "Not Saying Bye" << std::endl;
    co_return;
}

int main()
{
    auto hello_instance = hello();

    while (true) {
        try {
            std::cout << hello_instance.next() << std::endl;
        }
        catch (const Coro::StopIteration&) {
            break;
        }
    }

    return 0;
}
