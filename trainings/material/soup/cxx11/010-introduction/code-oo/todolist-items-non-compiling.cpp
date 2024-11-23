#include <map>
#include <string>
#include <iostream>

class Item_up_1_to_10
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

class Item_down_1000_to_980
{
public:
    void doit() const
    {
        for (int i=1000; i>=980; i--)
            std::cout << "DOWN: " << i << '\n';
    }
};

int main()
{
    using todo_list = std::map<std::string, Item>;     // <-- ???

    const todo_list tdl = {
        { "up 1 to 10", Item_up_1_to_10("blah") },
        { "down 1000 to 980", Item_down_1000_to_980() },
    };

    for (todo_list::const_iterator it=tdl.begin(); it!= tdl.end(); ++it) {
        std::string name = it->first;
        Item item = it->second;                        // <-- ???

        std::cout << "NAME: " << name << ", ";
        item.doit();
        std::cout << '\n';
    }

    return 0;
}
