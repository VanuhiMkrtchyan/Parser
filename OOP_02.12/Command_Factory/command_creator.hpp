#ifndef COMMAND_CREATOR_HPP
#define COMMAND_CREATOR_HPP

#include "../Commands/command.hpp"
#include "command_factory_registry.hpp"

class Command_Creator{
    public:
        std::unique_ptr<Command> create_command(const std::string&, const std::vector<std::string>&);
    private:
        Command_Factory_Registry factory_registry_;

};

#endif //COMMAND_CREATOR_HPP