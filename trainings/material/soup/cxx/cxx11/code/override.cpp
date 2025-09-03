#include <gtest/gtest.h>


class Interface
{
public:
    virtual ~Interface() {}

    virtual void a_method() = 0;
};

class OneImplementation : public Interface

