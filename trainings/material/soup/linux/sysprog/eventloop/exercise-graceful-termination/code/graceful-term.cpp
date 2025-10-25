#include "graceful-term.h"

#include <format>
#include <stdexcept>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <sys/signalfd.h>

GracefulTerminator::GracefulTerminator()
{
    sigset_t sigmask;
    sigemptyset(&sigmask);
    sigaddset(&sigmask, SIGTERM);
    sigaddset(&sigmask, SIGINT);

    _fd = signalfd(-1, &sigmask, 0);
    if (_fd == -1)
        throw std::runtime_error(std::format("signalfd: {} ({})", strerror(errno), errno));

    int rv = sigprocmask(SIG_BLOCK, &sigmask, nullptr);
    if (rv == -1) {
        close(_fd);
        _fd = -1;
        throw std::runtime_error(std::format("sigprocmask: {} ({})", strerror(errno), errno));
    }
}

GracefulTerminator::~GracefulTerminator()
{
    if (_fd == -1)
        close(_fd);
}

void GracefulTerminator::hookup(Eventloop& loop)
{
    loop.register_input(_fd, this);
}

EventAction GracefulTerminator::ready(int fd)
{
    assert(fd == _fd);

    signalfd_siginfo signals[2];                       // <-- SIGTERM, SIGINT
    ssize_t nread = read(fd, signals, sizeof(signals));
    if (nread == -1)
        throw std::runtime_error(std::format("read: {} ({})", strerror(errno), errno));

    for (size_t i=0; i<2; i++)
        switch (signals[i].ssi_signo) {
            case SIGTERM:
            case SIGINT:
                return EventAction::Quit;              // <-- what if the other signal is pending?
            default:
                assert(!"receiving signal that I did not request");
                break;
        }

    return EventAction::Continue;
}
