#pragma once

#include "queue.h"

#include <string>
#include <thread>
#include <future>
#include <memory>


class ServerThread
{
public:
    // in the remote thread, receives the "request", does with it
    // whatever needs to be done, and returns a "response" that is
    // sent back across the "network"
    class RemoteAdapter
    {
    public:
        virtual ~RemoteAdapter() {}
        virtual std::string execute(const std::string& request) = 0;
    };

public:
    ServerThread(RemoteAdapter*);
    ~ServerThread();

    // clients send a "request" packet across the "network". on the
    // remote side, that request is handed over to a RemoteAdapter
    // instance. that instance's return value, the "response" is then
    // sent back and returned.
    std::string write(const std::string& request);

private:
    struct Packet
    {
        std::string request;
        std::promise<std::string> response_promise;
    };

    RemoteAdapter* _adapter;
    MTQueue<Packet*> _queue;
    std::thread _thread;
};
