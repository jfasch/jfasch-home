#include <map>
#include <string>
#include <cstring>
#include <iostream>

class Item
{
public:
    virtual ~Item() = default;
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
    ~AllocatingItem() override
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
    Item* base = new AllocatingItem("blah");
    base->doit();
    delete base;

    return 0;
}
