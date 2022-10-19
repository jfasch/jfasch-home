#include "server-thread.h"

#include <iostream>


int main()
{
    ServerThread server_thread(std::make_unique<EchoServer>());

    std::string request = "abc";
    std::string response = server_thread.write(request);

    std::cout << response << std::endl;

    return 0;
}
