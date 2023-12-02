#ifndef ITEM_REGISTRY_HPP
#define ITEM_REGISTRY_HPP

#include <map>
#include <string>

#include "../Items/item.hpp"


class Item_Registry{
    public:
        using I_Registry = std::map<std::string, ItemPtr>;
    public:
        Item_Registry() = default;
        void item_register(const std::string&, ItemPtr);
        ItemPtr find_item(const std::string&);

    private:
        I_Registry registry_;
};

#endif //ITEM_REGISTRY_HPP