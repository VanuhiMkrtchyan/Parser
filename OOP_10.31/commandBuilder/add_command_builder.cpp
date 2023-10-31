#include "add_command_builder.hpp"


AddCommandBuilder::AddCommandBuilder(std::map<std::string, std::string> operands) : add_command{std::make_unique<Add_Command>()}{
    if(operands.fine("-item") != operands.end()){
        add_item_name(operands["-item"]);
    }
    if(operands.fine("-top_left") != operands.end()){
        add_item_name(operands["-top_left"]);
    }
    if(operands.fine("-bottom_right") != operands.end()){
        add_item_name(operands["-bottom_right"]);
    }
    if(operands.fine("-width") != operands.end()){
        add_item_name(operands["-width"]);
    }
    if(operands.fine("-height") != operands.end()){
        add_item_name(operands["-height"]);
    }
}


void AddCommandBuilder::add_item_name(std::string item_name){
    add_command->set_item_name(item_name);
}
void AddCommandBuilder::add_top_left(Item::Coord top_left){
    add_command->set_top_left(top_left);
}
void AddCommandBuilder::add_bottom_right(Item::Coord bottom_right){
    add_command->set_bottom_right(bottom_right);
}
void AddCommandBuilder::add_width(Item::Size width){
    add_command->set_width(width);
}
void AddCommandBuilder::add_height(Item::Size height){
    add_command->height = std::stoi(height);
}

void AddCommandBuilder::CommandPtr get_result(){
    return std::move(add_command);
}
    