#include "save_command.hpp"
#include <iostream>

void Save_Command::execute(I_Document& doc){
    std::string filename = *std::next(_arguments.begin());
    doc.save(filename);
    std::cout << "File " << filename << " is saved" << std::endl;
}

CommandPtr Save_Command::clone() const {
    return std::move(std::make_unique<Save_Command>());
}