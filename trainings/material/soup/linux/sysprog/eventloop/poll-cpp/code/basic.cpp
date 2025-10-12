#include "eventloop.h"

#include <sys/socket.h>
#include <gtest/gtest.h>


class ReceiveSingleBytesUntilQuit : public InputHandler
{
public:
    ReceiveSingleBytesUntilQuit(int fd) : _fd(fd) {}
    EventAction ready(int fd) override
    {
        assert(fd == _fd);
        char byte;
        ssize_t nread = read(_fd, &byte, 1);
        assert(nread != -1); // no error
        assert(nread != 0);  // no eof

        _num_called++;
        if (byte == 'q')
            return EventAction::Quit;
        else
            return EventAction::Continue;
    }

    int num_called() const { return _num_called; }

private:
    int _fd;
    int _num_called = 0;
};

TEST(eventloop_suite, quit)
{
    Eventloop loop;

    int pair[2];
    int error = socketpair(AF_UNIX, SOCK_STREAM, 0, pair);
    ASSERT_EQ(error, 0);

    ssize_t nwritten = write(pair[1], "123q", 4);
    ASSERT_EQ(nwritten, 4);

    ReceiveSingleBytesUntilQuit receiver(pair[0]);
    loop.register_input(pair[0], &receiver);

    loop.run();

    ASSERT_EQ(receiver.num_called(), 4);

    // only done on success, but ... well ...
    close(pair[0]);
    close(pair[1]);
}

