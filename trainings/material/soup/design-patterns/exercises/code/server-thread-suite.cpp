#include <gtest/gtest.h>

#include "server-thread.h"


class Echo : public ServerThread::RequestAdapter
{
public:
    std::string doit(const std::string& request)
    {
        return request;
    }
};

TEST(server_thread_suite, basic)
{
    ServerThread s(std::make_unique<EchoServer>());
    std::string request = "abc";
    std::string response = s.write(request);
    ASSERT_EQ(request, response);

    response = s.write("def");
    ASSERT_EQ(response, "def");
}
