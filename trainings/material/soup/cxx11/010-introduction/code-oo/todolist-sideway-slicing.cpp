#include <map>
#include <string>
#include <iostream>

class Item
{
public:
    void doit() const
    {
        std::cout << "don't know what to do";
    }
};

class Item_up_1_to_10 : public Item
{
public:
    Item_up_1_to_10(const std::string& prefix) : _prefix(prefix) {}
    void doit() const
    {
        for (int i=1; i<=10; i++)
            std::cout << _prefix << ", UP: " << i << '\n';
    }
private:
    std::string _prefix;
};

int main()
{
    Item_up_1_to_10 derived("blah");
    // derived.doit();                                 // <-- STEP 1: works, obviously

    Item base;
    base = derived;                                    // <-- STEP 2: *convert* (omit all that base hasn't)
    base.doit();                                       //             *not* correct (prints base nonsense)

    return 0;
}
