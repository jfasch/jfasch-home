#include <map>
#include <string>
#include <iostream>

class Item
{
public:
    Item() = default;                                  // <-- WTF? I don't want this!
    Item(const std::string& descr) : _descr(descr) {}
    void doit() const
    {
        std::cout << _descr;
    }
private:
    std::string _descr;
};

int main()
{
    using todo_list = std::map<std::string, Item>;

    todo_list tdl;
    tdl["up 1 to 10"] = Item("prefix: 'UP', count up from 1 to 10, interval 1 second");
    tdl["down 1000 to 980"] = Item("prefix: 'DOWN', count down from 1000 to 980, interval 0.5 second");

    for (todo_list::const_iterator it=tdl.begin(); it!= tdl.end(); ++it) {
        std::string name = it->first;
        Item item = it->second;

        std::cout << "NAME: " << name << ", ";
        item.doit();
        std::cout << '\n';
    }

    return 0;
}
