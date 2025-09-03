#pragma once

#include <coroutine>
#include <iterator>

template <typename T>
class Generator {
public:
    struct promise_type
    {
        Generator get_return_object() { return Generator(this); }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_always yield_value(T v)           // <--- called by co_yield  
        { 
            last_value = v;                            // <--- save yielded value
            return {};
        }
        std::suspend_always final_suspend() noexcept(true) { return {}; }
        void return_void() {}        
        void unhandled_exception() {}
        T last_value;                                  // <--- last value co_yield'ed
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
        T operator*() const
        {
            return coro.promise().last_value;
        }
    };

public:
    Generator(promise_type* p) : _promise(p) {}
    iterator begin() const { return {std::coroutine_handle<promise_type>::from_promise(*_promise)}; }
    sentinel end() const { return {}; }

private:
    promise_type* _promise;
};
