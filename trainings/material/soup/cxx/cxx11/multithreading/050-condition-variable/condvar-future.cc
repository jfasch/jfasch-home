#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>


// a Future can be thought of as a handle to something (of type T)
// that is not yet available (will be produced by a different thread).

// any thread that retrieves the element (using get()) will be
// suspended until the element is available.

// a thread that makes the element available wakes a possible waiter.
template <typename T> class Future
{
public:
    Future() : is_ready_(false) {}

    // if the element is available, it is returned
    // immediately. otherwise, the caller is suspended until the
    // element is available.
    T get()
    {
        std::unique_lock<std::mutex> guard(lock_);
        // wait(..., pred): does the bloody spurious wakeup loop
        // inside
        cond_ready_.wait(guard, [this]() { return this->is_ready_; });
        return value_;
    }

    // make the element available.
    void set(T value)
    {
        {
            std::unique_lock<std::mutex> guard(lock_);
            value_ = value;
            is_ready_ = true;
        }
        cond_ready_.notify_one();
    }
    
private:
    std::mutex lock_;
    bool is_ready_;
    std::condition_variable cond_ready_;

    T value_;
};


int main()
{
    Future<int> future;

    // this thread waits a couple of seconds and then produces the
    // element
    std::thread([&future]() {
            // countdown
            int i=5;
            while (i) {
                std::cout << i-- << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            // fire
            std::cout << "fire!" << std::endl;
            future.set(666);
        }).detach();

    // the main thread immediately get()s the element - which is not
    // likely to be available already.
    std::cout << "waiting for future" << std::endl;
    std::cout << "result: " << future.get() << std::endl;
}
