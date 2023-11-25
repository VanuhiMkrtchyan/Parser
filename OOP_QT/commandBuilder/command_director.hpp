#ifndef COMMAND_DIRECTOR_HPP
#define COMMAND_DIRECTOR_HPP

#include <map>
#include <string>
#include <variant>

#include "../Commands/command.hpp"
#include "command_builder.hpp"
#include "command_director.hpp"

using OptionsMap = std::map<std::string, std::variant<std::string, int, void>>;


class CommandDirector{
    public:
        CommandDirector() = default;
        CommandPtr construct(CommandBuilderPtr, OptionsMap options);
};

#endif //COMMAND_DIRECTOR_HPP