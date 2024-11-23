#include <map>
#include <string>
#include <iostream>

class Item
{
public:
    virtual void doit() const
    {
        std::cout << "don't know what to do";
    }
};

class YetAnotherItem : public Item
{
public:
    void doit()
    {
        std::cout << "Doing yet another thing";
    }
};

int main()
{
    YetAnotherItem derived;

    Item* base;
    base = &derived;
    base->doit();

    return 0;
}
