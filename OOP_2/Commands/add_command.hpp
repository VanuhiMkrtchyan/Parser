#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "command.hpp"

class Add_Command : public Command{
    public:
        Add_Command() = default;
        void execute() override;
};

#endif //ADD_COMMAND_HPP