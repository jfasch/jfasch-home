#ifndef BAG_UNIQUE_H
#define BAG_UNIQUE_H

#include <vector>
#include <string>
#include <memory>

class BagUnique
{
public:
    using Item = std::pair<std::string, int>;

    void insert(std::unique_ptr<Item>&& itemp)
    {
        _items.push_back(std::move(itemp));
    }
    const Item* find_by_int(int i) const
    {
        for (const auto& item: _items)
            if (item->second == i)
                return item.get();
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
    std::vector<std::unique_ptr<Item>> _items;
};

#endif
