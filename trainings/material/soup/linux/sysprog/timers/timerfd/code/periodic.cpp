#include <sys/timerfd.h>
#include <stdio.h>
#include <unistd.h>
#include <print>

int main()
{
    int timer = timerfd_create(CLOCK_MONOTONIC, 0);
    if (timer == -1) {
        perror("timerfd_create");
        return 1;
    }

    struct itimerspec sp = {
        {1,0},                                         // <-- 1 second interval
        {3,0},
    };
    int rv = timerfd_settime(timer, 0 /*relative*/,
                             &sp,
                             nullptr);
    if (rv == -1) {
        perror("timerfd_settime");
        return 1;
    }

    while (true) {
        uint64_t num_expirations;
        ssize_t nread = read(timer, &num_expirations, sizeof(num_expirations));
        if (nread == -1) {
            perror("read");
            return 1;
        }
        if (nread != sizeof(num_expirations)) {
            std::println(stderr, "well, something's severely wrong");
            return 1;
        }

        std::println("#expirations: {}", num_expirations);
    }

    return 0;
}
