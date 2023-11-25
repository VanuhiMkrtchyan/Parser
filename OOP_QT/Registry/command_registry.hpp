#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP

#include <map>
#include <string>

#include "../Commands/command.hpp"
#include "../Commands/add_command.hpp"

class CommandRegisrty{
    public:
        CommandRegisrty();
        CommandPtr const operator[](const std::string);
        std::map<std::string, CommandPtr> Cmd_Reg;
};

#endif //COMMAND_REGISTRY_HPP
