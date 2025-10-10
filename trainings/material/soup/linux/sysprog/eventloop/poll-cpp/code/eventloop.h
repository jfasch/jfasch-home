#pragma once

#include <map>


class InputHandler
{
public:
    virtual ~InputHandler() = default;
    virtual void ready(int fd) = 0;
};

class Eventloop
{
public:
    void register_input(int fd, InputHandler*);
    void run_once();

private:
    std::map<int, InputHandler*> _inputs;    
};
