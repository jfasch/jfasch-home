#include <sys/timerfd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <assert.h>


int main(void)
{
    // allocate space (in kernel) for a timer. the handle to it is a
    // FILE DESCRIPTOR, again.
    int fd = timerfd_create(CLOCK_MONOTONIC, 0);

    // configure timer chip, setup an interrupt service routine, blah,
    // and start timer. the timer is a periodic timer.
    {
        int error;
        struct itimerspec ts = {
            // interval
            { 
                1,             // 1 second
                0              // 0 nanoseconds
            },
            // initial expiration
            {
                3,             // 3 seconds
                500*1000*1000, // 0.5 seconds
            }
        };

        error = timerfd_settime(fd, 0, &ts, NULL);

        // error handling
        if (error == -1) {
            perror("timerfd_settime()");
            exit(1);
        }
    }        
    
    // allocate buffer, and *read* in a loop until done. reading from
    // a timer is defined as reading an uint64_t - the number of
    // expirations since the last wakeup.
    while (1) {
        uint64_t expirations;
        ssize_t nbytes_read = read(fd, &expirations, sizeof(expirations));
        assert(nbytes_read == sizeof(expirations));  // no way seeing
                                                     // end-of-file
        printf("expired\n");
    }

    // free resources (won't get here though)
    close(fd);

    return 0;
}
