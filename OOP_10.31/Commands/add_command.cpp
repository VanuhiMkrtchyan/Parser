#include "add_command.hpp"

void Add_Command::execute(){
    ItemPtr item = item_factory.create_item(item_name);
    item.set_width(width);
    ///TODO: save_in_doc;
}
void Add_Command::set_ID_count(static int ID){
    ID_count = ID;
}
static int Add_Command::get_ID_Count(){
    return ID_count;
}

void Add_Command::set_item_name(std::string name){
    item_name = name;
}
std::string Add_Command::get_item_name(){
    return item_name;
}

void Add_Command::set_top_left(Item::Coord left){
    top_left = left;
}
Item::Coord Add_Command::get_top_left(){
    return top_left;
}

void Add_Command::set_bottom_right(Item::Coord right){
    bottom_right = right;
}
Item::Coord Add_Command::get_bottom_left(){
    return bottom_right;
}

void Add_Command::set_width(Item::Size w){
    width = std::stoi(w);
}
Item::Size Add_Command::get_width(){
    return width;
}

void Add_Command::set_height(Item::Size h){
    height = std::stoi(h);
}
Item::Size Add_Command::get_height(){
    return height;
}
