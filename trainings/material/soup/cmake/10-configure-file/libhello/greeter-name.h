#ifndef GREETER_NAME_H
#define GREETER_NAME_H

#include "greeter.h"
#include <string>

class NameGreeter : public Greeter
{
public:
    NameGreeter(const std::string& name) : _name(name) {}
    void sayhello() override;

private:
    std::string _name;
};

#endif
