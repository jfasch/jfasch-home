#ifndef GREETER_SIMPLE_H
#define GREETER_SIMPLE_H

#include "greeter.h"

class SimpleGreeter : public Greeter
{
public:    
    void sayhello() override;
};

#endif
