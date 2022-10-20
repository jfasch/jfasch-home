#pragma once

#include "queue.h"

#include <string>
#include <thread>
#include <future>
#include <memory>


class ServerThread
{
public:
    class RequestAdapter
    {
    public:
        virtual ~RequestAdapter() {}
        virtual std::string doit(const std::string& request) = 0;
    };

public:
    ServerThread(std::unique_ptr<RequestAdapter> intp);
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
    std::unique_ptr<RequestAdapter> _adapter;
    MTQueue<std::shared_ptr<Packet>> _queue;
    std::thread _thread;
};
