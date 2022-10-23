#pragma once

#include <thread>
#include <condition_variable>
#include <mutex>
#include <stdexcept>
#include <deque>


template <typename T>
class MTQueue
{
public:
    MTQueue(size_t maxsize) : _maxsize(maxsize) {}

    void push(T elem)
    {
        {
            std::unique_lock<std::mutex> guard(_lock);

            _notfull.wait(guard, [this](){ return _queue.size() != _maxsize; });
            _queue.push_back(elem);
        }
        _notempty.notify_one();
    }

    T pop()
    {
        T rv;
        {
            std::unique_lock<std::mutex> guard(_lock);

            _notempty.wait(guard, [this](){ return _queue.size()>0; });
            rv = _queue.front();
            _queue.pop_front();
        }
        _notfull.notify_one();
        
        return rv;
    }

private:
    std::deque<T> _queue;
    size_t _maxsize;
    std::mutex _lock;
    std::condition_variable _notempty;
    std::condition_variable _notfull;
};
