#include "command_creator.hpp"

std::unique_ptr<Command> Command_Creator::create_command(const std::string &commandName, const std::vector<std::string> &args)
{
    auto command_factory = factory_registry_.find_factory(commandName);
    return command_factory->make_command(args);   
}