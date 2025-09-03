#include <sys/timerfd.h>
#include <unistd.h>
#include <cassert>
#include <utility>
#include <iostream>

class PeriodicTimer{
public:
    PeriodicTimer(timespec interval)
    : _fd(timerfd_create(CLOCK_MONOTONIC, 0)),
      _interval(interval)
    {
        assert(_fd>=0);
    }
    ~PeriodicTimer()
    {
        close(_fd);
    }

    PeriodicTimer(const PeriodicTimer&) = delete;
    PeriodicTimer& operator=(const PeriodicTimer&) = delete;

    PeriodicTimer(PeriodicTimer&& from)
    : _fd(std::exchange(from._fd, -1)),
      _interval(std::exchange(from._interval, {0})) {}
    PeriodicTimer& operator=(PeriodicTimer& from)
    {
        if (this != &from) {
            _fd = std::exchange(from._fd, -1);
            _interval = std::exchange(from._interval, {0});
        }
        return *this;
    }

    void start()
    {
        itimerspec spec = {
            .it_interval = _interval,
            .it_value = {0,1}                          // <-- initial expiration: (almost) now
        };
        int error = timerfd_settime(_fd, 0, &spec, nullptr);
        assert(!error);
    }

    uint64_t /*n expirations*/ wait()
    {
        uint64_t num_expirations;
        ssize_t n_bytes_read = read(_fd, &num_expirations, sizeof(num_expirations));
        assert(n_bytes_read == sizeof(num_expirations));
        return num_expirations;
    }

private:
    int _fd;
    timespec _interval;
};

void do_something_with(PeriodicTimer&& timer)
{
    auto my_timer = std::move(timer);
    for (int i=0; i<3; i++) {
        sleep(2);
        uint64_t n_expirations = my_timer.wait();
        std::cout << "timer expired " << n_expirations << " times" << std::endl;
    }
}

int main()
{
    PeriodicTimer timer({0,1000UL*1000UL});            // <-- millisecond
    timer.start();

    // auto another_timer = timer;                     // <-- no!

    do_something_with(std::move(timer));

    return 0;
}
