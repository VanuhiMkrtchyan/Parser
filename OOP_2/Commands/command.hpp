#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <memory>

class Command{
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
};

using CommandPtr = std::unique_ptr<Command>;

#endif //COMMAND_HPP