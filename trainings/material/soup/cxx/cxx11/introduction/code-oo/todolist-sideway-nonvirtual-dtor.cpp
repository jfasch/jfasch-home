#include <map>
#include <string>
#include <cstring>
#include <iostream>

class Item
{
public:
    virtual void doit() const = 0;
};

class AllocatingItem : public Item
{
public:
    AllocatingItem(const char* descr)
    : _descr(new char[strlen(descr)+1])
    {
        strcpy(_descr, descr);
    }
    ~AllocatingItem()
    {
        delete[] _descr;
    }
    void doit() const override
    {
        std::cout << "Allocated space for: " << _descr;
    }

private:
    char* _descr;
};

int main()
{
    AllocatingItem derived("blah");

    Item* base;
    base = &derived;
    base->doit();

    return 0;
}
