#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include <memory>
#include <string>
#include <vector>

#include "../Commands/command.hpp"
#include "../Parser/tokenizer.hpp"

using CommandPtr = std::unique_ptr<Command>;

class Command_Factory{
    public:
        Tokenizer tokenizer_;
    public:
        virtual CommandPtr create_command(const std::string& input) = 0;
        virtual ~Command_Factory(){}
};

using CommandFactoryPtr = std::unique_ptr<Command_Factory>;

#endif //COMMAND_FACTORY_HPP