#ifndef SAVE_COMMAND_HPP
#define SAVE_COMMAND_HPP

#include "command.hpp"
#include "../Document/document.hpp"

class Save_Command : public Command{
    public:
        void execute(I_Document&) override;
        CommandPtr clone() const override;
};

#endif //SAVE_COMMAND_HPP