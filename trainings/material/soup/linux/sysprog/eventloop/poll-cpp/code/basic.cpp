#include "eventloop.h"

#include <sys/socket.h>
#include <gtest/gtest.h>


class MyReceiver : public InputHandler
{
public:
    MyReceiver(int fd) : _fd(fd) {}
    void ready(int fd) override
    {
        assert(fd == _fd);
        char buf[64];
        ssize_t nread = read(_fd, buf, sizeof(buf));
        assert(nread != -1); // no error
        assert(nread != 0);  // no eof

        _received = std::string(buf, nread);
    }

    const std::string& received() const { return _received; }

private:
    int _fd;
    std::string _received;
};

TEST(eventloop_suite, basic)
{
    Eventloop loop;

    int pair[2];
    int error = socketpair(AF_UNIX, SOCK_STREAM, 0, pair);
    ASSERT_EQ(error, 0);

    ssize_t nwritten = write(pair[1], "yay", 3);
    assert(nwritten == 3);

    MyReceiver receiver(pair[0]);
    loop.register_input(pair[0], &receiver);

    loop.run_once();

    ASSERT_EQ(receiver.received(), "yay");

    // only done on success, but ... well ...
    close(pair[0]);
    close(pair[1]);
}
