#include <coroutine>
#include <iostream>
#include <iterator>

class Coro {
public:
    struct promise_type
    {
        Coro get_return_object() { return Coro(this); }
        std::suspend_never initial_suspend() { return {}; }
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

    struct sentinel {};
    struct iterator
    {
        std::coroutine_handle<promise_type> coro;
        bool operator==(sentinel) const { return coro.done(); }
        iterator& operator++()
        {
            coro.resume();
            return *this;
        }
        std::string operator*() const
        {
            return coro.promise().last_value;
        }
    };

public:
    Coro(promise_type* p) : _promise(p) {}
    iterator begin() const { return {std::coroutine_handle<promise_type>::from_promise(*_promise)}; }
    sentinel end() const { return {}; }

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

    for (auto elem: hello_instance)
        std::cout << elem << std::endl;

    return 0;
}
