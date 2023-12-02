#include "add_command_factory.hpp"
#include "../Commands/add_command.hpp"

std::unique_ptr<Command> Add_Command_Factory::make_command(const std::vector<std::string>& input){
    auto command = std::make_unique<Add_Command>(doc_);
    auto tokens = Command_Factory::tokenizer_.tokenize(command);
    std::unique_ptr<Item> item_ = item_registry_[tokens[2]]->create_item(tokens);
    
    return command;
}
std::unique_ptr<Command_Factory> Add_Command_Factory::clone() const{
    return std::make_unique<Add_Command_Factory>(doc_);
} 