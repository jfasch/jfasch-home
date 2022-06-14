#ifndef BAG_UNIQUE_H
#define BAG_SHARED_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>

class BagShared
{
public:
    using Item = std::pair<std::string, int>;

    void insert(const std::shared_ptr<Item>& itemp)
    {
        _items.push_back(std::move(itemp));
    }
    std::weak_ptr<Item> insert(std::shared_ptr<Item>&& itemp)
    {
        std::shared_ptr<Item> stolen = std::move(itemp);
        _items.push_back(stolen);
        return std::weak_ptr<Item>(stolen);
    }
    std::shared_ptr<Item> find_by_int(int i) const
    {
        for (const auto& item: _items)
            if (item->second == i)
                return item;
        return nullptr;
    }
    unsigned remove_by_int(int i)
    {
        std::size_t nremoved{};
        for (auto it=_items.begin(); it!=_items.end();) {
            if ((*it)->second == i) {
                it = _items.erase(it);
                ++nremoved;
            }
            else
                ++it;
        }
        return nremoved;
    }
    
private:
    std::vector<std::shared_ptr<Item>> _items;
};

#endif
