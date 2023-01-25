#pragma once

class Base
{
public:
    const char* method() const
    {
        return "I am an instance of class Base";
    }
};

class Derived : public Base
{
public:
    const char* method() const
    {
        return "I am an instance of class Derived";
    }
};

