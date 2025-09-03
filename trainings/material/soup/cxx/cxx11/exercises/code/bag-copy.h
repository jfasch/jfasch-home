#ifndef BAG_COPY_H
#define BAG_COPY_H

#include <vector>
#include <string>

class BagCopy
{
public:
    using Item = std::pair<std::string, int>;

    void insert(Item item)
    {
        _items.push_back(item);
    }
    Item find_by_int(int i) const
    {
        for (auto item: _items)
            if (item.second == i)
                return item;
        return Item();
    }
    unsigned remove_by_int(int i)
    {
        std::size_t nremoved{};
        for (auto it=_items.begin(); it!=_items.end(); ++it) {
            if (it->second == i) {
                it = _items.erase(it);
                ++nremoved;
            }
        }
        return nremoved;
    }
    
private:
    std::vector<Item> _items;
};

#endif
