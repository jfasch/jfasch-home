#ifndef GREETER_H
#define GREETER_H

class Greeter
{
public:
    virtual ~Greeter() {}
    virtual void sayhello() = 0;
};

#endif
