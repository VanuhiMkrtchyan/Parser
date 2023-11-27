#include "command_builder_factory.hpp"

CommandBuilderPtr CommandBuilderFactory::create_command_builder(std::string command_name, std::map<std::string, std::string> operands){
    if(command_name == "add"){
        return std::make_unique<AddCommandBuilder>(operands);
    }
 }