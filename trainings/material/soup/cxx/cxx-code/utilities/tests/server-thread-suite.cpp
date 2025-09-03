#include <gtest/gtest.h>

#include <server-thread.h>


class Echo : public jf::utilities::ServerThread::RemoteAdapter
{
public:
    std::string execute(const std::string& request)
    {
        return request;
    }
};

TEST(server_thread_suite, basic)
{
    Echo echo;
    jf::utilities::ServerThread s(&echo);
    std::string request = "abc";
    std::string response = s.write(request);
    ASSERT_EQ(request, response);

    response = s.write("def");
    ASSERT_EQ(response, "def");
}
