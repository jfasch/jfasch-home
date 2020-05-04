#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


#define _SYSE(ret, msg) do {                    \
    if (ret == -1) {                            \
        perror(msg);                            \
        exit(EXIT_FAILURE);                     \
    }                                           \
} while (0)

static int /*bool: EOF detected*/ consume_fd(int fd, const char* msg)
{
    char tmp[64];
    ssize_t nread;

    nread = read(fd, tmp, sizeof(tmp));
    _SYSE(nread, "read");
    if (nread == 0 /*EOF*/)
        return 1;

    printf("%s: consumed %ld bytes\n", msg, nread);
    return 0;
}

int main(void)
{
    int random_fd, tty_fd, nfds = 0;

    random_fd = open("/dev/random", O_RDONLY);
    _SYSE(random_fd, "open random");
    if (random_fd > nfds)
        nfds = random_fd+1;

    tty_fd = open("/dev/ttyS4", O_RDONLY);
    _SYSE(tty_fd, "open tty");
    if (tty_fd > nfds)
        nfds = tty_fd+1;

    while (1) {
        fd_set in_fds;
        int ret;

        FD_ZERO(&in_fds);
        FD_SET(random_fd, &in_fds);
        FD_SET(tty_fd, &in_fds);

        ret = select(nfds, &in_fds, NULL, NULL, NULL);
        _SYSE(ret, "select");

        if (FD_ISSET(random_fd, &in_fds)) {
            int eof_detected = consume_fd(random_fd, "random");
            if (eof_detected) 
                break;
        }
        if (FD_ISSET(tty_fd, &in_fds)) {
            int eof_detected = consume_fd(tty_fd, "tty");
            if (eof_detected) 
                break;
        }
    }
    return 0;
}
