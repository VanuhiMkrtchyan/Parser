#include "add_command.hpp"
#include <iostream>

Add_Command::Add_Command(std::shared_ptr<Document> doc) : document_{doc}{}

std::string Add_Command::execute(){
    document_->get_current_slide().add_item(std::move(curr_item));
    return "item is added";
}

Command::CommandPtr Add_Command::clone() const{
    return std::make_unique<Add_Command>();
}

void Add_Command::set_item(std::unique_ptr<Item> item){
    curr_item = std::move(item);
}

void Add_Command::set_type(Item::Type type){
    type_ = type;
}