#include "item_registry.hpp"
#include <execution>



void Item_Registry::item_register(const std::string& i_name, ItemPtr item){
    registry_[i_name] = std::move(item);
}

ItemPtr Item_Registry::find_item(const std::string& i_name){
    auto item_i = registry_.find(i_name);
    if( item_i == registry_.end()){
        throw std::runtime_error(std::string("wrong item name"));
    }
    return item_i->second->clone();
}
