#ifndef COMMAND_BUILDER_FACTORY_HPP
#define COMMAND_BUILDER_FACTORY_HPP

#include <map>
#include <functional>

#include "../commandBuilder/command_builder.hpp"
#include "../commandBuilder/add_command_builder.hpp"


class CommandBuilderFactory{
    public:
        CommandBuilderFactory();
        CommandBuilderPtr create_command_builder(std::string command_name, std::map<std::string, std::string> operands);
    private:
        std::map<std::string, std::function<CommandBuilderPtr()>> command_builder;
};

#endif //COMMAND_BUILDER_FACTORY_HPP