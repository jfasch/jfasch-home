#pragma once

#include "queue.h"

#include <string>
#include <thread>
#include <future>
#include <memory>


class EchoServer
{
public:
    std::string doit(const std::string& request)
    {
        return request;
    }
};

class ServerThread
{
public:
    ServerThread(std::unique_ptr<EchoServer> server);
    ~ServerThread();

    std::string write(const std::string& request);

private:
    struct Packet
    {
        Packet(const std::string& request) : request(request) {}
        std::string request;
        std::promise<std::string> response_promise;
    };

private:
    std::unique_ptr<EchoServer> _server;
    MTQueue<std::shared_ptr<Packet>> _queue;
    std::thread _thread;
};
