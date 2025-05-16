class Base
{
public:
    virtual void method1() final {}
    virtual void method2() {}
};

class Derived : public Base
{
public:
    virtual void method1() final {}
    virtual void method2() {}
};
