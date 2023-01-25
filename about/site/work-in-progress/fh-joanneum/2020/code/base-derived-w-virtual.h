#pragma once

class Base
{
public:
    virtual const char* method() const
    {
        return "I am an instance of class Base";
    }
};

class Derived : public Base
{
public:
    virtual const char* method() const
    {
        return "I am an instance of class Derived";
    }
};

