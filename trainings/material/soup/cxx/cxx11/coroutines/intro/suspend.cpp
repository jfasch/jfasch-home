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
    void resume() { std::coroutine_handle<promise_type>::from_promise(*_promise).resume(); }
    std::string last_value() const { return _promise->last_value; }

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
    hello_instance.resume();                           // <--- yields into promise
    auto value = hello_instance.last_value();          // <--- get yielded value from promise
    std::cout << "coro produced: " << value << std::endl;
    hello_instance.resume();                           // <--- terminate: resume until co_return
    return 0;
}
