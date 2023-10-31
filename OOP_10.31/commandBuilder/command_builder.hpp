#ifndef COMMAND_BUILDER_HPP
#define COMMAND_BUILDER_HPP

#include "../Items/item.hpp"
#include "../Commands/command.hpp"

class CommandBuilder{
    public:
        virtual void add_item_name();
        virtual void add_top_left();
        virtual void add_bottom_right();
        virtual void add_ID();
        virtual void add_width();
        virtual void add_height();
        virtual CommandPtr get_result();
};

using CommandBuilderPtr = std::unique_ptr<CommandBuilder>;
#endif //COMMAND_BUILDER_HPP