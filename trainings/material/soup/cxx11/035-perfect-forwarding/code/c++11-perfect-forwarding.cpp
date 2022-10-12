#include <iostream>
#include <vector>
using namespace std;

class Item
{
public:
    Item(int value) : _value(value) {}
    Item(const Item& item)
    {
        cout << "Item(const Item&)" << endl;
        _value = item._value;
    }
    Item(Item&& item)
    {
        cout << "Item(Item&&)" << endl;
        _value = item._value;
        item._value = 666;
    }

    int value() const { return _value; }

private:
    int _value;
};

class Container
{
public:
    template <typename T>
    void add(T&& item)
    {
        _items.push_back(std::forward<T>(item));
    }

    // void add(const Item& item) 
    // {
    //     _items.push_back(item);
    // }
    // void add(Item&& item) 
    // {
    //     _items.push_back(move(item));
    // }

private:
    vector<Item> _items;
};


int main()
{
    Container c;
    Item item(42);

    cout << "1" << endl;
    c.add(item);
    cout << "2" << endl;
    c.add(move(item));
    cout << "3" << endl;

    return 0;
}
