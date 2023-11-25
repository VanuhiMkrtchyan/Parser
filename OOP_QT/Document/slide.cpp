#include "slide.hpp"

void Slide::add_item(ItemPtr item){
    items[item_id++] = std::move(item);
}

void Slide::change_item(int ID){
    auto item = find_item(ID);
}

void Slide::remove_item(int ID){
    auto item = find_item(ID);
    items.erase(item);
}

std::string Slide::get_all_items(){
    std::string result;
    for(auto [id, item] : items){
        result += id + " " + item->type() + "\n";
    }
    return result;
}

ItemPtr Slide::get_item_byID(int ID){
    auto item = find_item(ID);
    return item->second();
}

ItemMap::iterator Slide::find_item(int ID){
    auto item = items.find(ID);
    if(item == items.end()){
        throw std::runtime_error("Item not found");
    }
    return item;
}