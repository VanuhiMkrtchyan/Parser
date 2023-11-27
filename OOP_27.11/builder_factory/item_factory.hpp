#ifndef ITEM_BUILDER_FACTORY_HPP
#define ITEM_BUILDER_FACTORY_HPP

#include <map>
#include <memory>
#include <functional>
#include <string>

#include "../Items/item.hpp"
#include "../Items/rectangle.hpp"


class ItemBuilderFactory{
    public:
        ItemBuilderFactory();
        ItemPtr create_item(std::string);
};

#endif //ITEM_BUILDER_FACTORY_HPP