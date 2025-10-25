#include "commit-rollback.h"

#include <format>
#include <stdexcept>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <sys/signalfd.h>

#include <print>

CommitRollbackSigHandler::CommitRollbackSigHandler(Database& db)
: _db(db)
{
    sigset_t sigmask;
    sigemptyset(&sigmask);
    sigaddset(&sigmask, SIGUSR1);
    sigaddset(&sigmask, SIGUSR2);

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

CommitRollbackSigHandler::~CommitRollbackSigHandler()
{
    if (_fd == -1)
        close(_fd);
}
    
void CommitRollbackSigHandler::hookup(Eventloop& loop)
{
    loop.register_input(_fd, this);
}

EventAction CommitRollbackSigHandler::ready(int fd)
{
    assert(fd == _fd);

    signalfd_siginfo signals[2];                       // <-- SIGUSR1, SIGUSR2
    ssize_t nread = read(fd, signals, sizeof(signals));
    if (nread == -1)
        throw std::runtime_error(std::format("read: {} ({})", strerror(errno), errno));

    for (size_t i=0; i < nread / sizeof(signalfd_siginfo); i++)
        switch (signals[i].ssi_signo) {
            case SIGUSR1:
                _db.commit();
                break;
            case SIGUSR2:
                _db.rollback();
                break;
            default:
                std::println("{}", strsignal(signals[i].ssi_signo));
                assert(!"receiving signal that I did not request");
                break;
        }

    return EventAction::Continue;
}
