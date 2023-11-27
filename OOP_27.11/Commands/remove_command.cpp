#include "remove_command.hpp"

#include <iostream>

void Remove_Command::execute(I_Document& doc){
    auto id = *std::next(get_arguments().begin());
    doc.remove_item(std::stoi(id));
    std::cout << "Item is deleted" << std::endl;
}

CommandPtr Remove_Command::clone() const{
    return std::move(std::make_unique<Remove_Command>());
}