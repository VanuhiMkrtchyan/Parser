#ifndef COMMAND_REGISTRY
#define COMMAND_REGISTRY

// #include <unordered_map>
#include <map>
# include <string>

// #include "command.hpp"
#include "child_commands.hpp"

using CmdRegistry = std::map<std::string, Command*>;

class CommandRegistry{
    public:
        CommandRegistry();
        ~CommandRegistry();
       Command* const operator[](const std::string);
        bool comand_exists(const std::string command);
    //private:
        CmdRegistry command_registry;

};


#endif //COMMAND_REGISTRY
