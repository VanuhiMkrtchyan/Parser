#ifndef REMOVE_COMMAND_HPP
#define REMOVE_COMMAND_HPP

#include "command.hpp"

class Remove_Command{
    public:
        void execute(I_Document&) override;
        CommandPtr clone() const override;
};

#endif //REMOVE_COMMAND_HPP