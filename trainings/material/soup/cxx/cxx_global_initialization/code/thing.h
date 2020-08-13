#include <iostream>
#include <string>


#ifndef __HAVE_THING_H__
#define __HAVE_THING_H__

class Thing
{
public:
    Thing(const std::string& content) : _content(content)
    {
        std::cout << "ctor: " << _content << std::endl;
    }
    ~Thing()
    {
        std::cout << "dtor: " << _content << std::endl;
    }

    const std::string& content() const { return _content; }

private:
    std::string _content;
};

#endif
