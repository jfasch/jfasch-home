#include <iostream>


class Interface
{
public:
    virtual ~Interface() {}
    virtual void do_this() = 0;
    virtual void do_that() = 0;
};

class OneImplementation : public Interface
{
public:
    virtual void do_this()
    {
        std::cout << "OneImplementation doing this" << std::endl;
    }
    virtual void do_that()
    {
        std::cout << "OneImplementation doing that" << std::endl;
    }
};

class AnotherImplementation : public Interface
{
public:
    virtual void do_this()
    {
        std::cout << "AnotherImplementation doing this" << std::endl;
    }
    virtual void do_that()
    {
        std::cout << "AnotherImplementation doing that" << std::endl;
    }
};

class Client
{
public:
    Client(Interface *iface) : interface(iface) {}

    void do_much_work()
    {
        interface->do_this();
        interface->do_that();
    }

private:
    Interface *interface;
};

int main()
{
    OneImplementation one;
    AnotherImplementation another;
    Client c_using_one(&one);
    Client c_using_another(&another);

    c_using_one.do_much_work();
    c_using_another.do_much_work();
}
