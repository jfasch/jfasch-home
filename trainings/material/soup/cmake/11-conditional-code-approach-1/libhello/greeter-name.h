#ifndef GREETER_NAME_H
#define GREETER_NAME_H

#include "greeter.h"

#include <DemoConfig.h>                                // <--- dependency in header file!!!
#if DEMO_USE_BLACKLIST == 1                            
#  include <blacklist.h>                               // <--- dependency in header file!!!
#endif

#include <string>

class NameGreeter : public Greeter
{
public:
    NameGreeter(const std::string& name) : _name(name) {}
    void sayhello() override;

private:
    std::string _name;

#if DEMO_USE_BLACKLIST == 1                            // <--- dependency in header file!!!
    Blacklist _blacklist;
#endif
};

#endif
